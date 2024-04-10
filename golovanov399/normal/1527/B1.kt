import java.util.*
import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    val s = readLine()!!
    val cnt = s.count { it == '0' }
    if (cnt % 2 == 1) {
        val a = 1
        val b = cnt - 1
        println(if (a < b) "ALICE" else "BOB")
    } else {
        println(if (cnt == 0) "DRAW" else "BOB")
    }
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}