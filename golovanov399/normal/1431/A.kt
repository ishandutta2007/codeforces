import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toLong).sorted().reversed().toLongArray()
    var ans = 0L
    for (i in 0 until n) {
        ans = max(ans, a[i] * (i + 1))
    }
    println(ans)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}