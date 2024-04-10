import kotlin.math.*

fun solve() {
    val (n, k) = readLine()!!.split(' ').map(String::toInt)
    val s = readLine()!!
    val bal = s.scan(0) { b, c -> b + (if (c == '(') 1 else -1) }
    val cnt = (0..n step 2).count { bal[it] > 0 }
    println(min(cnt, k) + bal.count { it == 0 } - 1)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}