import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val (n, k) = readLine()!!.split(' ').map(String::toInt)
    val s = readLine()!!
    val total_ones = s.count { it == '1' }
    var ans = total_ones
    for (i in 0 until k) {
        var cur = arrayListOf<Char>()
        for (j in i until n step k) {
            cur.add(s[j])
        }
        var pref = IntArray(cur.size + 1) {0}
        for (t in 0 until cur.size) {
            pref[t + 1] = pref[t] + (if (cur[t] == '1') 1 else -1)
        }
        for (t in 1..cur.size) {
            pref[t] = min(pref[t - 1], pref[t])
        }
        var zeros_count = cur.count { it == '0' }
        var cur_suf = 0
        for (t in cur.indices.reversed()) {
            ans = min(ans, total_ones - cur.size + zeros_count + zeros_count + cur_suf + pref[t + 1])
            cur_suf += if (cur[t] == '1') 1 else -1
        }
    }
    println(ans)
}

fun main() {
    val t = readLine()!!.toInt()

    for (i in 0 until t) {
        solve()
    }
}