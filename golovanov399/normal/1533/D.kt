import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val (n, _) = readLine()!!.split(' ').map(String::toInt)
    val s = (0 until n).map { readLine()!! }.toSet()
    val q = readLine()!!.toInt()
    repeat (q) {
        val t = readLine()!!
        println(t.indices.asSequence().filter { i -> i == 0 || t[i] != t[i - 1] }.map { i -> t.take(i) + t.drop(i + 1) }.filter { it in s }.count())
    }
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}