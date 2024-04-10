import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val (n, s) = readLine()!!.split(' ').map(String::toInt)
    if (s >= 2 * n) {
        println("YES")
        var a = IntArray(n) {1}
        a[0] = s - n + 1
        println(a.joinToString(" "))
        println(n)
    } else {
        println("NO")
    }
}

fun main() {
//    val t = readLine()!!.toInt()
    val t = 1

    for (i in 0 until t) {
        solve()
    }
}