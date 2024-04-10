import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val (n, k) = readLine()!!.split(' ').map(String::toInt)
    val a = readLine()!!.split(' ').map(String::toInt).sorted().toIntArray()
    var p = IntArray(n + 1) { 0 }
    for (i in 0 until n) {
        p[i + 1] = p[i] + a[i]
    }
    var ans = 0
    for (l in 1..n) {
        ans = max(ans, p[n - l + l / k] - p[n - l])
    }
    println(ans)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}