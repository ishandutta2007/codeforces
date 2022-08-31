import java.util.*
import kotlin.system.exitProcess

fun solve() {
    val (n, a, b) = readLine()!!.split(' ').map(String::toInt)
    val pattern = CharArray(b) { i -> 'a' + i }.joinToString("")
    val other_bs = CharArray(a - b) { 'a' + (b - 1) }.joinToString("")
    var s = ""
    while (s.length < n) {
        if (s.length + pattern.length <= n) {
            s += pattern
        } else {
            s += pattern.take(n - s.length)
        }
        if (s.length + other_bs.length <= n) {
            s += other_bs
        } else {
            s += other_bs.take(n - s.length)
        }
    }
    println(s)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}