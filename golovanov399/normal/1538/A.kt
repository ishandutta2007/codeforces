import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt)
    var l = a.indexOf(a.minOrNull()!!)
    var r = a.indexOf(a.maxOrNull()!!)
    if (l > r) {
        val x = l
        l = r
        r = x
    }
    println(n - maxOf(l, r - l - 1, n - r - 1))
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}