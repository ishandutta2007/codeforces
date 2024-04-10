import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val (n, k) = readLine()!!.split(' ').map(String::toInt)
    val a = n / (1 + k + k * k + k * k * k)
    println("$a ${a*k} ${a*k*k} ${a*k*k*k}")
}

fun main() {
    val t = readLine()!!.toInt()

    repeat (t) {
        solve()
    }
}