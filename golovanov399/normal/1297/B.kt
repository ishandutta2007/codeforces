import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val n = readLine()!!.toInt()
    var a = mutableListOf<Pair<Int, Int>>()
    for (i in 0 until n) {
        val (l, r) = readLine()!!.split(' ').map(String::toInt)
        a.add(Pair(l, -1))
        a.add(Pair(r + 1, 1))
    }
    a.sortWith(compareBy({ it.first }, { it.second }))
    var balance = 0
    var i = 0
    while (i < a.size) {
        val cur = a[i].first
        while (i < a.size && a[i].first == cur) {
            balance -= a[i].second
            i += 1
        }
        if (balance == 1) {
            println(cur)
            return
        }
    }
    println(-1)
}

fun main() {
    val t = readLine()!!.toInt()

    for (i in 0 until t) {
        solve()
    }
}