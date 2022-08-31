import kotlin.math.*

const val inf = 1e9.toInt()

fun solve() {
    val n = readLine()!!.toInt()
    val s = readLine()!!
    val a = readLine()!!
    val initial = List(8) { mask ->
        (0 until 3).count { i ->
            (s[2 - i] == '(') == ((mask and (1 shl i)) > 0)
        }
    }
    var dp = initial
    for (i in a.indices) {
        val c = a[i]
        val nw = MutableList(8) { inf }
        for (mask in (0 until 8)) {
            for (sym in "()") {
                if (c == '1' && (sym == '(' || (mask and 4) > 0)) {
                    continue
                }
                if (c == '1' && (mask and 3) !in listOf(1, 2)) {
                    continue
                }
                val nMask = ((mask * 2) + if (sym == '(') 0 else 1) and 7
                nw[nMask] = min(nw[nMask], dp[mask] + if (sym != s[i + 3]) 1 else 0)
            }
        }
        dp = nw
    }
    val ans = dp.minOrNull()!!
    println(if (ans > n) -1 else ans)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}