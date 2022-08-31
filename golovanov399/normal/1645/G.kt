import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.map { it - 'a' }
    val b = readLine()!!.map { it - 'a' }
    val c = a.zip(b).map { (x, y) -> x + y }.toMutableList()
    for (i in n - 1 downTo 1) {
        c[i - 1] += c[i] / 26
        c[i] %= 26
    }
    for (i in 0 until n) {
        if (i < n - 1) {
            c[i + 1] += c[i] % 2 * 26
        }
        c[i] /= 2
    }
    println(c.map { 'a' + it }.joinToString(""))
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}