import kotlin.math.*

fun solve() {
    val s = readLine()!!
    val cnt = "ABC".map { c -> s.count { it == c } }
    if (2 * cnt.maxOrNull()!! != s.length) {
        println("NO")
        return
    }
    val mx = 'A' + cnt.withIndex().maxByOrNull { it.value }!!.index
    val t = s.map { c -> if ((c == mx) == (mx == s[0])) 1 else -1 }
    println(if (t.scan(0, Int::plus).minOrNull()!! == 0) "YES" else "NO")
}

fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}