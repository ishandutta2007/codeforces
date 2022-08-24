import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val (n, k1, k2) = readLine()!!.split(' ').map(String::toInt)
    val s = readLine()!!
    var a = mutableListOf<Int>()
    var cur = 0
    for (c in s) {
        if (c == '1') {
            cur += 1
        } else {
            if (cur > 0) {
                a.add(cur)
            }
            cur = 0
        }
    }
    if (cur > 0) {
        a.add(cur)
    }
    var ans = 0L
    for (x in a) {
        if (k2 >= 2 * k1) {
            ans += 1L * x * k1
        } else {
            ans += 1L * x / 2 * k2 + x % 2 * k1
        }
    }
    println(ans)
}

fun main() {
    val t = readLine()!!.toInt()

    repeat (t) {
        solve()
    }
}