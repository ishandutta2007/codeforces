import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val (n, m) = readLine()!!.split(' ').map(String::toInt)
    println(min(n - 1, 2) * m)
}

fun main() {
    val t = readLine()!!.toInt()

    for (i in 0 until t) {
        solve()
    }
}