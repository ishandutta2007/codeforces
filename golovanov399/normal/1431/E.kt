import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt).toIntArray()
    val b = readLine()!!.split(' ').map(String::toInt).toIntArray()
    var ans = 0
    var opt = 0
    for (l in 0 until n) {
        var cur = 1000000000
        for (i in 0 until n) {
            cur = min(cur, abs(a[i] - b[(i + l) % n]))
        }
        if (cur > ans) {
            ans = cur
            opt = l
        }
    }
    for (i in 0 until n) {
        print("${(i + opt) % n + 1} ")
    }
    println()
}

fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}