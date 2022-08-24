import kotlin.math.*

fun solve() {
    val (n, x) = readLine()!!.split(' ').map(String::toLong)
    var a = readLine()!!.split(' ').map(String::toInt).toMutableList()
    for (i in 0 until n.toInt()) {
        a.add(a[i])
    }
    var p = LongArray(2 * n.toInt() + 1) {0}
    var p2 = LongArray(2 * n.toInt() + 1) {0}
    for (i in 0 until 2 * n.toInt()) {
        p[i + 1] = p[i] + a[i]
        p2[i + 1] = p2[i] + 1L * a[i] * (a[i] + 1) / 2
    }
    var ans = 0L
    run {
        var j = 0
        for (i in 0 until n.toInt()) {
            while (p[j + 1] - p[i] <= x) {
                j += 1
            }
            ans = max(ans, p2[j] - p2[i] + 1L * (x - p[j] + p[i]) * (x - p[j] + p[i] + 1) / 2)
        }
    }
    run {
        var i = 0
        for (j in n.toInt() + 1 until 2 * n.toInt() + 1) {
            while (p[j] - p[i] > x) {
                i += 1
            }
            ans = max(ans, p2[j] - p2[i] + 1L * (x - p[j] + p[i]) * (2 * a[i - 1] - (x - p[j] + p[i]) + 1) / 2)
        }
    }
    println(ans)
}

fun main() {
    val t = 1; // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}