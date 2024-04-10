import kotlin.math.*

fun solve() {
    val (n, m, k) = readLine()!!.split(' ').map(String::toInt)
    if (m <= n / k) {
        println(m)
    } else {
        println(n / k - (m - n / k + k - 2) / (k - 1))
    }
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}