import kotlin.math.*

fun commonSuffix(s: String, t: String): Int {
    var ans = 0
    while (ans < s.length && ans < t.length && s[s.length - 1 - ans] == t[t.length - 1 - ans]) {
        ++ans
    }
    return ans
}

fun solve() {
    val n = readLine()!!.toInt()
    var mn = 0
    var mx = Int.MAX_VALUE
    repeat (n) {
        val (s, t, r) = readLine()!!.split(' ')
        if (r == "1") {
            mx = min(mx, commonSuffix(s, t))
        } else {
            mn = max(mn, commonSuffix(s, t) + 1)
        }
    }
    if (mx < mn) {
        mx = mn - 1
    }
    println(mx - mn + 1)
    println((mn..mx).toList().joinToString(" "))
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}