import java.util.*
import kotlin.math.*

const val mod = 1_000_000_007

fun pw(_a: Int, _b: Int): Long {
    var a = _a.toLong()
    var b = _b.toLong()
    var res = 1L
    while (b > 0) {
        if (b % 2 > 0) {
            res = res * a % mod
        }
        b /= 2
        a = a * a % mod
    }
    return res
}

fun solve() {
    val (n, m) = readLine()!!.split(' ').map(String::toInt)
    var cnt = 0
    repeat (n) {
        val s = readLine()!!
        cnt += s.count { it == '#' }
    }
    println(pw(2, cnt) - (if (cnt == n * m) 1 else 0))
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}