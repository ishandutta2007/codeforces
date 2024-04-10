import java.util.*
import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    val s = readLine()!!
    var cnt = 0
    var nonsym = 0
    for (i in 0 until n) {
        if (s[i] == '0') {
            if (s[n - 1 - i] != '0') {
                nonsym += 1
            } else {
                cnt += 1
            }
        }
    }
    if (nonsym == 0) {
        if (cnt % 2 == 1) {
            val a = 1
            val b = cnt - 1
            println(if (a < b) "ALICE" else "BOB")
        } else {
            println(if (cnt == 0) "DRAW" else "BOB")
        }
    } else if (nonsym == 1 && cnt == 1) {
        println("DRAW")
    } else {
        println("ALICE")
    }
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}