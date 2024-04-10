import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val (n, l, r) = readLine()!!.split(' ').map(String::toInt)
    val a = readLine()!!.split(' ').map(String::toInt).sorted()
    fun f(x: Int): Long {
        var ans = 0L
        var j = n
        for (y in a) {
            while (j > 0 && y + a[j - 1] > x) {
                --j
            }
            ans += j
        }
        return (ans - a.count { it * 2 <= x }) / 2
    }
    println(f(r) - f(l - 1))
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}