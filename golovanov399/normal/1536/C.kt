import java.util.*
import kotlin.math.*

fun gcd(x: Int, y: Int): Int = if (y == 0) x else gcd(y, x % y)

fun solve() {
    val n = readLine()!!.toInt()
    val s = readLine()!!
    val mp = mutableMapOf<Pair<Int, Int>, Int>()
    var (x, y) = listOf(0, 0)
    val ans = mutableListOf<Int>()
    for (c in s) {
        if (c == 'D') {
            x += 1
        } else {
            y += 1
        }
        val g = gcd(x, y)
        val p = Pair(x / g, y / g)
        ans.add((mp[p]?:0) + 1)
        mp[p] = (mp[p]?:0) + 1
    }
    println(ans.joinToString(" "))
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}