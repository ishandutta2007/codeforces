import kotlin.math.*

fun solve() {
    val s = readLine()!!
    println(if ("ab".all { c -> s.split(c).all { it.length != 1 } }) "YES" else "NO")
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}