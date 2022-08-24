import kotlin.math.*

fun solve() {
    val (n, add) = readLine()!!.split(' ').map(String::toInt)
    val a = readLine()!!.split(' ').map(String::toInt)
    val p = a.scan(0L) { x, y -> x + y }
    val mx = (0..n).map { len -> (0..n-len).map { i -> p[i + len] - p[i] }.maxOrNull()!! }.toMutableList()
    val ans = mutableListOf<Long>()
    ans.add(mx.maxOrNull()!!)
    for (i in 1..n) {
        for (j in i..n) {
            mx[j] = mx[j] + add
        }
        ans.add(mx.maxOrNull()!!)
    }
    println(ans.joinToString(" "))
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}