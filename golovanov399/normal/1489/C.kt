import java.util.*
import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    val s = readLine()!!
    var ans = 0
    var cnt = 0
    for (c in s) {
        if (c == 'x') {
            cnt += 1
            if (cnt >= 3) {
                ans += 1
            }
        } else {
            cnt = 0
        }
    }
    println(ans)
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}