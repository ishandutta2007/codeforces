import kotlin.math.*

fun solve() {
    val (n, m, x, y) = readLine()!!.split(' ').map(String::toInt)
    val a = List<String>(n) {readLine()!!}
    var max_double = 0
    var whites = 0
    for (s in a) {
        var cur = 0
        for (c in s) {
            if (c == '.') {
                cur += 1
                whites += 1
            } else {
                cur = 0
            }
            if (cur == 2) {
                max_double += 1
                cur = 0
            }
        }
    }
    println(1L * (whites - 2 * max_double) * x + min(2 * x, y) * 1L * max_double)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}