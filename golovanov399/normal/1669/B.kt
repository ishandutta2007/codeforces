import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt)
    val cnt = MutableList(n) { 0 }
    a.forEach { x -> cnt[x - 1] += 1 }
    for (i in 0 until n) {
        if (cnt[i] >= 3) {
            println(i + 1)
            return
        }
    }
    println(-1)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}