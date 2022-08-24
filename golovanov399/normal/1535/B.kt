import kotlin.math.*

fun gcd(x: Int, y: Int): Int = if (y == 0) x else gcd(y, x % y)

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt).sortedBy { it % 2 }
    var ans = 0
    for (i in 0 until n) {
        for (j in 0 until i) {
            if (gcd(2 * a[i], a[j]) > 1) {
                ans += 1
            }
        }
    }
    println(ans)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}