import kotlin.math.min
import kotlin.system.exitProcess

fun main() {
    var (n, k) = readLine()!!.split(' ').map(String::toLong)
    var cost = 0L
    var options = mutableListOf<Pair<Long, Long>>()
    var can = 0L
    for (i in 0 until n) {
        val (a, b, c) = readLine()!!.split(' ').map(String::toLong)
        k -= a
        cost += a.toLong() * c
        options.add(Pair(c, b - a))
        can += b - a
    }
    if (k < 0 || can < k) {
        println(-1)
        exitProcess(0)
    }
    options.sortBy { it.first }
    for (i in 0 until n.toInt()) {
        val cnt = min(options[i].second, k)
        k -= cnt
        cost += options[i].first * cnt.toLong()
    }
    println(cost)
}