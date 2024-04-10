import kotlin.math.*

fun solve() {
    val (x, y) = readLine()!!.split(' ').map(String::toInt)
    println(y % x + (y / x).toString().sumBy { c -> (c.hashCode() - '0'.hashCode()) })
}

fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}