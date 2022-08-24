import kotlin.math.*

fun solve() {
    val (n, k) = readLine()!!.split(' ').map(String::toInt)
    val l = (k + 1) / 2
    val r = n
    println(r - l)
    println((l..r).filter { it != k }.joinToString(" "))
}

fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}