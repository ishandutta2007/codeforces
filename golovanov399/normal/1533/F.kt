import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val a = readLine()!!.map { it - '0' }.scan(0, Int::plus)
    println((1 until a.size).map { k ->
        var ans = 0
        var i = 0
        while (i < a.size - 1) {
            ans += 1
            var (l, r) = listOf(min(i + k, a.size - 1), a.size)
            while (r > l + 1) {
                val mid = (l + r) / 2
                if (a[mid] - a[i] in (k + 1) until mid - i - k) {
                    r = mid
                } else {
                    l = mid
                }
            }
            i = l
        }
        ans
    }.joinToString(" "))
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}