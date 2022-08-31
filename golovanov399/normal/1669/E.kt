import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    val cnt = List(11) { IntArray(11) { 0 } }
    repeat (n) {
        val s = readLine()!!
        cnt[s[0] - 'a'][s[1] - 'a'] += 1
    }
    var ans = 0L
    for (i in 0..10) {
        for (j in 0..10) {
            val cur = cnt[i][j].toLong()
            for (k in 0 until i) {
                ans += cur * cnt[k][j]
            }
            for (k in 0 until j) {
                ans += cur * cnt[i][k]
            }
        }
    }
    println(ans)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}