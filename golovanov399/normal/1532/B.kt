import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val (a, b, k) = readLine()!!.split(' ').map(String::toLong)
    println(k / 2 * (a - b) + k % 2 * a)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}