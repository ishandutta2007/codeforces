import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt)
    val x = readLine()!!.toInt()
    val b = a.map { x - it }
    var minShit = LongArray(a.size + 1) {0}
    run {
        var cur = 0L
        for (i in b.indices) {
            cur += b[i]
            minShit[i + 1] = min(minShit[i], cur)
        }
    }
    var sum = a.map { it.toLong() }.sum()
    var k = (n + 1) / 2
    while (k <= n && sum + minShit[n - k] <= 0) {
        sum += x
        k += 1
    }
    if (k > n) {
        k = -1
    }
    println(k)
}

fun main() {
    val t = 1; // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}