import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun f(x: Long, y: Long, a: Int, r: Int, m: Int): Long {
    return a * x + r * y - (a + r - m) * min(x, y)
}

fun solve() {
    var (n, a, r, m) = readLine()!!.split(' ').map(String::toInt)
    m = min(m, a + r)
    val v = readLine()!!.split(' ').map(String::toInt).sorted()
    var pr = LongArray(n + 1) {0}
    for (i in 0 until n) {
        pr[i + 1] = pr[i] + v[i]
    }

    fun lb(x: Int): Int {
        var l = -1
        var r = n
        while (r > l + 1) {
            val m = (l + r) / 2
            if (v[m] >= x) {
                r = m
            } else {
                l = m
            }
        }
        return r
    }

    fun g(x: Int): Long {
        val i = lb(x)
        return f(1L * i * x - pr[i], pr[n] - pr[i] - 1L * (n - i) * x, a, r, m)
    }

    var ans: Long = 1e18.toLong()
    var lo = 0L
    var hi = (1e9 + 10).toLong()
    while (hi > lo + 2) {
        val m1 = (2 * lo + hi) / 3
        val m2 = (lo + 2 * hi) / 3
        if (g(m1.toInt()) >= g(m2.toInt())) {
            lo = m1
        } else {
            hi = m2
        }
    }
    for (x in lo..hi) {
        ans = min(ans, g(x.toInt()))
    }
//    for (i in 0 until n) {
//        ans = min(ans, f(1L * i * v[i] - pr[i], pr[n] - pr[i] - 1L * (n - i) * v[i], a, r, m))
//    }
    println(ans)
}

fun main() {
//    val t = readLine()!!.toInt()
    val t = 1

    for (i in 0 until t) {
        solve()
    }
}