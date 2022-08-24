import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val (_, k, x) = readLine()!!.split(' ').map(String::toLong)
    val a = readLine()!!.split(' ').map(String::toLong).sorted().distinct()
    val ns = a.zipWithNext().map { (l, r) -> (r - l - 1) / x }.sorted()
    println(a.size - ns.scan(0L, Long::plus).indexOfLast { it <= k })
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}