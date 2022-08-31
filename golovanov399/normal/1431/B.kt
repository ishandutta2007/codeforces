import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val s = readLine()!!
    var ans = s.count { it == 'w' }
    var cnt = 0
    for (c in s) {
        if (c == 'v') {
            ++cnt
        } else {
            ans += cnt / 2
            cnt = 0
        }
    }
    ans += cnt / 2
    println(ans)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}