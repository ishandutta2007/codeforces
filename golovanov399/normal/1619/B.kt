import kotlin.math.*

fun sqr(x: Int) = x * x;

fun mypow(a: Int, d: Int): Int = if (d == 1) a else if (d % 2 > 0) mypow(a, d - 1) * a else sqr(mypow(a, d / 2))

fun f(n: Int, d: Int): Int {
    var l = 1
    var r = n.toDouble().pow(1.0 / d).roundToInt() + 5
    while (r > l + 1) {
        val m = (l + r) / 2
        if (mypow(m, d) <= n) {
            l = m
        } else {
            r = m
        }
    }
    return l
}

fun solve() {
    val n = readLine()!!.toInt()
    println(f(n, 2) + f(n, 3) - f(n, 6))
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}