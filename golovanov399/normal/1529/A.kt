import java.util.*
import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt)
    println(n - a.count { it == a.minOrNull()!! })
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}