import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt)
    val cnt = MutableList(n + 1) { 0 }
    a.forEach { cnt[it] += 1 }
    var curNeed = 0L
    val rest = mutableListOf<Int>()
    val ans = (0..n).map { i ->
        if (curNeed == -1L) {
            -1
        } else {
            val res = curNeed + cnt[i]
            if (cnt[i] == 0) {
                if (rest.isEmpty() || rest.last() >= i) {
                    curNeed = -1L
                } else {
                    curNeed += i - rest.removeLast()
                }
            } else {
                repeat (cnt[i] - 1) {
                    rest.add(i)
                }
            }
            res
        }
    }
    println(ans.joinToString(" "))
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}