import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    var (n, k) = readLine()!!.split(' ').map(String::toInt)
    val a = readLine()!!.split(' ').map(String::toInt)
    val b = List<Pair<Int, Int>>(a.size) { i -> Pair(a[i], i) }.sortedBy { it.first }
    val last = b.last().first.toLong()
    var ans = MutableList<Int>(a.size) { 0 }
    for (i in a.indices.reversed()) {
        val want = last - (n - 1 - i)
        val diff = min(want - b[i].first, k.toLong())
        k -= diff.toInt()
        ans[b[i].second] += diff.toInt()
        if (k == 0) {
            break
        }
    }
    ans = ans.map { x -> x + k / n }.toMutableList()
    k %= n
    if (k > 0) {
        for (i in 1..k) {
            ans[b[b.size - i].second] += 1
        }
    }
    println(ans.joinToString(separator = " "))
}

fun main() {
    val t = readLine()!!.toInt()

    for (i in 0 until t) {
        solve()
    }
}