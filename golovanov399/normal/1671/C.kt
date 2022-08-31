import kotlin.math.*

fun solve() {
    val (n, x) = readLine()!!.split(' ').map(String::toInt)
    val a = readLine()!!.split(' ').map(String::toLong).sorted().scan(0L, Long::plus)
    var last = -1L
    var ans = 0L
    for (i in n downTo 1) {
        if (x - a[i] < 0) {
            continue
        }
        val till = (x - a[i]) / i
        ans += (till - last) * i
        last = till
    }
    println(ans)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}