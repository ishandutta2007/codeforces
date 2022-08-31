import kotlin.math.*

const val L = 31

fun solve() {
    val (n, k) = readLine()!!.split(' ').map(String::toInt)
    val a = readLine()!!.split(' ').map(String::toInt)
    val cnt = (0 until L).map { i ->
        a.count { it and (1 shl i) == 0 }
    }
    var rem = k
    var ans = 0
    for (i in L - 1 downTo 0) {
        if (cnt[i] <= rem) {
            rem -= cnt[i]
            ans += 1 shl i
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