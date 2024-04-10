import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt)
    val order = a.withIndex().sortedByDescending { it.value }.map { it.index }
    println(order.withIndex().map { (i, v) -> a[v] * i + 1 }.sum())
    println(order.map(Int::inc).joinToString(" "))
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}