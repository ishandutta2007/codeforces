import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt)
    val s = a.sum()
    if (s % n > 0) {
        println("-1")
    } else {
        val avg = s / n
        println(a.count { it > avg })
    }
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}