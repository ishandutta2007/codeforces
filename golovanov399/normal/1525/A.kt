import kotlin.math.*

fun solve() {
    val k = readLine()!!.toInt()
    println(100 / gcd(k, 100))
}

tailrec fun gcd(x: Int, y: Int): Int = if (y == 0) x else gcd(y, x % y)

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}