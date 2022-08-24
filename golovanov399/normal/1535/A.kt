import java.math.BigDecimal
import java.math.RoundingMode
import kotlin.math.*

fun solve() {
    val s = readLine()!!.split(' ').map(String::toInt)
    val t = s.sorted()
    println(if (s[0] + s[1] == t[2] + t[3] || s[2] + s[3] == t[2] + t[3]) "NO" else "YES")
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}