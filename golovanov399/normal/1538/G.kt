import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val (x, y, a, b) = readLine()!!.split(' ').map(String::toInt)

    fun isGood(cnt: Int): Boolean {
        if (cnt <= x / a && cnt <= y / b) {
            return true
        }
        if (cnt <= x / b && cnt <= y / a) {
            return true
        }
        if (min(a, b) * cnt > min(x, y)) {
            return false
        }
        return (x - min(a, b) * cnt) / (max(a, b) - min(a, b)) + (y - min(a, b) * cnt) / (max(a, b) - min(a, b)) >= cnt
    }

    var (l, r) = listOf(0, (x + y) / (a + b) + 1)
    while (r > l + 1) {
        val m = (l + r) / 2
        if (isGood(m)) {
            l = m
        } else {
            r = m
        }
    }
    println(l)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}