import java.util.*
import kotlin.system.exitProcess

fun solve() {
    val n = readLine()!!.toInt()
    println((n - 1) / 2)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}