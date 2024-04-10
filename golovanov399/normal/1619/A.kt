import kotlin.math.*

fun solve() {
    val s = readLine()!!
    val n = s.length
    println(if (s.take(n / 2) == s.takeLast(n / 2) && n % 2 == 0) "Yes" else "No")
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}