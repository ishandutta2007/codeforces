import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    val blocks = readLine()!!.split('W')
    if (blocks.all { it.isEmpty() || !it.all { c -> c == it[0] } }) {
        println("YES")
    } else {
        println("NO")
    }
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}