import java.util.*
import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt).sorted()
    if (a.maxOrNull()!! <= 0) {
        println(n)
        return
    }
    val mn = a.filter { it > 0 }.minOrNull()!!
    var only_nonpos = a.filter { it <= 0 }.size
    var ans = 1
    var cur = mn
    for (x in a.reversed()) {
        if (x <= cur - mn) {
            ans += 1
            cur = x
        }
    }
    println(max(ans, only_nonpos))
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}