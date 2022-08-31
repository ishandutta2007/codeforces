import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val (n, m) = readLine()!!.split(' ').map(String::toInt)
    var a = LongArray(n) { 0L }
    var edges = mutableListOf<List<Int>>()
    repeat (m) {
        val (u, v, w) = readLine()!!.split(' ').map(String::toInt)
        a[u - 1] = max(a[u - 1], w.toLong())
        a[v - 1] = max(a[v - 1], w.toLong())
        edges.add(listOf(u - 1, v - 1, w))
    }
    for ((u, v, w) in edges) {
        if (min(a[u], a[v]) != w.toLong()) {
            println("NO")
            return
        }
    }
    println("YES")
    println(a.joinToString(" "))
}

fun main() {
    val t = readLine()!!.toInt()

    repeat (t) {
        solve()
    }
}