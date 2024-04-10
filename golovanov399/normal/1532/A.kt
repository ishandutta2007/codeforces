import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    println(readLine()!!.split(' ').map(String::toInt).sum())
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}