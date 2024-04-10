import kotlin.math.*

fun solve() {
    readLine()!!
    val (a, va) = readLine()!!.split(' ').map(String::toInt)
    val (c, vc) = readLine()!!.split(' ').map(String::toInt)
    val b = readLine()!!.toInt()
    println(min(vc, b - a + va))
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}