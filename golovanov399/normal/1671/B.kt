import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt)
    fun check(s: Int): Boolean = a.withIndex().all { (index, value) -> abs(value - index - s) <= 1 }
    println(if ((-1..1).any { check(a[0] + it) }) "YES" else "NO")
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}