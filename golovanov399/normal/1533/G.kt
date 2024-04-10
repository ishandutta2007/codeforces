import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val (n, m) = readLine()!!.split(' ').map(String::toInt)
    val a = (0 until n).map { readLine()!!.split(' ').map(String::toInt) }
    val startX = a.indexOfFirst { it.any { x -> x > 0 } }
    val startY = a[startX].indexOfFirst { x -> x > 0 }

    val used = MutableList(n) { MutableList(m) { false } }
    used[startX][startY] = true
    val seq = mutableListOf<Int>()

    fun dfs(x: Int, y: Int) {
        seq.add(a[x][y])
        for (dx in -1..1) {
            for (dy in -1..1) {
                if (abs(dx) + abs(dy) != 1) {
                    continue
                }
                val (nx, ny) = listOf(x + dx, y + dy)
                if (nx !in 0 until n || ny !in 0 until m) {
                    continue
                }
                if (used[nx][ny] || a[nx][ny] == 0) {
                    continue
                }
                used[nx][ny] = true
                dfs(nx, ny)
                seq.add(a[x][y])
            }
        }
    }

    dfs(startX, startY)
    val side = (seq.size + 1) / 2
    if (side < a.sumOf { l -> l.count { x -> x > 0 } }) {
        println(-1)
        return
    }

    println("$side $side")
    (0 until side).forEach { i -> println(seq.subList(i, i + side).joinToString(" ")) }
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}