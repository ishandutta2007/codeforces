import kotlin.math.*

fun solve() {
    val (a, b) = readLine()!!.split(' ').map(String::toInt)
    if (b == 1) {
        println("No")
    } else {
        println("Yes")
        println("$a ${a.toLong() * (2 * b - 1)} ${a.toLong() * 2 * b}")
    }
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}