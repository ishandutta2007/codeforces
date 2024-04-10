import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt)
    val x = a.sorted()[n / 2]
    println(a.indexOfFirst { it != x } + 1)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}