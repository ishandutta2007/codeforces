import java.util.*
import kotlin.system.exitProcess

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt).toIntArray()
    println((a.sum() + n - 1) / n)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}