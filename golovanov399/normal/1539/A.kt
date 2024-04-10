import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val (n, x, t) = readLine()!!.split(' ').map(String::toInt)
    val m = (t / x).toLong()
    println(if (m < n) (m * n - m * (m + 1) / 2) else (n.toLong() * (n.toLong() - 1) / 2))
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}