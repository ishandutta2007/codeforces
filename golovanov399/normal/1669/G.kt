import kotlin.math.*

fun solve() {
    val (n, m) = readLine()!!.split(' ').map(String::toInt)
    val a = (0 until n).map { readLine()!!.toMutableList() }
    for (j in 0 until m) {
        var low = n - 1
        for (i in n - 1 downTo 0) {
            if (a[i][j] == 'o') {
                low = i - 1
            } else if (a[i][j] == '*') {
                a[i][j] = '.'
                a[low][j] = '*'
                low -= 1
            }
        }
    }
    println(a.joinToString("\n") { it.joinToString("") })
    println()
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}