import kotlin.math.*

fun solve() {
    val s = readLine()!!
    val c = readLine()!![0]
    println(if (c in s.chunked(2).map { it[0] }) "Yes" else "No")
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}