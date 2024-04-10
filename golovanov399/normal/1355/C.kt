import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun f(c: Int, a: Int, b: Int): Long {
    if (c < 0) {
        return 0;
    } else if (c <= min(a, b)) {
        return 1L * (c + 1) * (c + 2) / 2
    } else if (c <= max(a, b)) {
        return 1L * (min(a, b) + 1) * (min(a, b) + 2) / 2 + 1L * (min(a, b) + 1) * (c - min(a, b))
    } else if (c <= a + b) {
        return 1L * (a + 1) * (b + 1) - 1L * (a + b - c) * (a + b - c + 1) / 2
    } else {
        return 1L * (a + 1) * (b + 1)
    }
}

fun solve() {
    val (a, b, c, d) = readLine()!!.split(' ').map(String::toInt)
    var ans: Long = 1L * (b - a + 1) * (c - b + 1) * (d - c + 1)
    for (z in c..d) {
        ans -= f(z - a - b, b - a, c - b)
    }
    println(ans)
}

fun main() {
//    val t = readLine()!!.toInt()
    val t = 1

    for (i in 0 until t) {
        solve()
    }
}