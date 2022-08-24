import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    readLine()
    println(readLine()!!.split(' ').asSequence().map(String::toInt).sorted().withIndex().sumOf { (if (it.index % 2 == 1) 1 else -1) * it.value })
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}