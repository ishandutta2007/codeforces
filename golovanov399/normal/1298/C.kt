import kotlin.math.*
import kotlin.system.exitProcess

fun main() {
    val n = readLine()!!.toInt()
    val s = readLine()!!

    var ans = 0
    var cur = 0
    for (c in s) {
        if (c == 'x') {
            cur += 1
        } else {
            ans += max(cur - 2, 0)
            cur = 0
        }
    }
    ans += max(cur - 2, 0)
    println(ans)
}