import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    val s = mutableSetOf<Int>()
    var cur = n
    while (cur !in s) {
        s.add(cur)
        cur += 1
        while (cur % 10 == 0) {
            cur /= 10
        }
    }
    println(s.size)
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}