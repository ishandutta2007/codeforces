import kotlin.math.*

const val mod = 998_244_353

fun solve() {
    val n = readLine()!!.toInt()
    val s = readLine()!!
    var ans = 1

    var l = s.length / 2 + 1
    var cur = s.drop(l - 1).map { it - 'A' }
    while (l % 2 == 0) {
        repeat (cur.chunked(2).count { it[0] != it[1] }) {
            ans *= 2
            if (ans >= mod) {
                ans -= mod
            }
        }
        val d = mutableMapOf<List<Int>, Int>()
        l /= 2
        cur = cur.chunked(2).withIndex().map { (i, v) ->
            val tmp = v.sorted() + listOf(s[l - 1 + i] - 'A')
            if (!d.containsKey(tmp)) {
                d[tmp] = d.size
            }
            d[tmp]!!
        }
    }
    println(ans)
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}