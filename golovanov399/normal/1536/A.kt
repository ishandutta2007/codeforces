import java.util.*
import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt)
    if (a.minOrNull()!! < 0) {
        println("No")
        return
    }
    println("Yes")
    println(101)
    println((0..100).joinToString(" "))
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}