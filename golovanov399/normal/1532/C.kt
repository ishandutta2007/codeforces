import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val (n, k) = readLine()!!.split(' ').map(String::toInt)
    println((0 until n).map { 'a' + (it % k) }.joinToString(""))
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}