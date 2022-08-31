import kotlin.math.*

fun solve() {
    val (n, _x, _y) = readLine()!!.split(' ').map(String::toInt)
    val x = min(_x, _y)
    val y = max(_x, _y)
    println((x until y).map { i -> max(i - 1 + min(i - x, x - 1), n - i - 1 + min(n - y, y - i - 1)) }.minOrNull()!!)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}