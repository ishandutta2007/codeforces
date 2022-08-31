import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val n = readLine()!!.toInt()
    if (n < 1000) {
        println(n)
    } else if (n < 999500) {
        println("${(n + 500) / 1000}K")
    } else {
        println("${(n + 500000) / 1000000}M")
    }
}

fun main() {
    val t = readLine()!!.toInt()

    for (i in 0 until t) {
        solve()
    }
}