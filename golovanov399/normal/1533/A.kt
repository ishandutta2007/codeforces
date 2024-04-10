import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val (n, k) = readLine()!!.split(' ').map(String::toInt)
    println((0 until n).map { readLine()!!.split(' ').map(String::toInt) }.map { (s, f) -> if (k in s..f) (f - k + 1) else 0 }.maxOrNull()!!)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}