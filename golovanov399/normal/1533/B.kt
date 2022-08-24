import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    readLine()
    val a = readLine()!!.split(' ').map(String::toInt)
    println(if (a.zipWithNext().any { (x, y) -> x % 2 == y % 2 }) "YES" else "NO")
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}