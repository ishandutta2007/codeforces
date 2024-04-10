import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    val k = (0..n).first { i -> i * (i + 1) / 2 == n }
    val s = readLine()!!
    println((0 until k).map { i -> s[i * (i + 1) / 2] }.joinToString(""))
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}