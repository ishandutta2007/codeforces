import kotlin.math.*

fun solve() {
    val (n, x) = readLine()!!.split(' ').map(String::toInt)
    val a = readLine()!!.split(' ').map(String::toInt)
    val initial = a.zipWithNext().sumOf { (x, y) -> abs(x - y).toLong() }
    val mn = a.minOrNull()!!
    val mx = a.maxOrNull()!!
    if (mx >= x) {
        println(initial + minOf(
                a[0] - 1,
                a[n - 1] - 1,
                2 * (mn - 1)
        ))
    } else {
        println(initial + x - mx + mn - 1
                + (if (mn in listOf(a[0], a[n - 1])) 0 else minOf(mn - 1, a[0] - mn, a[n - 1] - mn))
                + (if (mx in listOf(a[0], a[n - 1])) 0 else minOf(x - mx, mx - a[0], mx - a[n - 1]))
        )
    }
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}