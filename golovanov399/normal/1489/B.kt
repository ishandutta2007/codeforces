import java.util.*
import kotlin.math.*

fun solve() {
    val (n, a, b) = readLine()!!.split(' ').map(String::toLong)
    println(min(n / 2 * b + n % 2 * a, n * a))
}

fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}