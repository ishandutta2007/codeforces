import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val (n, q) = readLine()!!.split(' ').map(String::toInt)
    val p = readLine()!!.map { c -> c - 'a' + 1 }.scan(0, Int::plus)
    repeat (q) {
        val (l, r) = readLine()!!.split(' ').map(String::toInt)
        println(p[r] - p[l - 1])
    }
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}