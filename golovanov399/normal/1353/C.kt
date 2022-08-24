import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val k = readLine()!!.toLong() / 2
    println(k * (k + 1) * (2 * k + 1) / 6 * 8)
}

fun main() {
    val t = readLine()!!.toInt()

    for (i in 0 until t) {
        solve()
    }
}