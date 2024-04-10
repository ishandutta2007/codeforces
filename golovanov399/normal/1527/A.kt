import java.util.*
import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    var m = 1
    while (m * 2 <= n) {
        m *= 2
    }
    println(m - 1)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}