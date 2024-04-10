import kotlin.math.*

fun solve() {
    val (n, s) = readLine()!!.split(' ').map(String::toLong)

    fun check(m: Long): Boolean {
        var cnt = 0
        var total = 0L
        var x = m
        while (cnt < n && x > 1) {
            total += x
            if (total > s) {
                return false
            }
            x = (x + 1) / 2
            cnt += 1
        }
        total += n - cnt
        return total <= s
    }

    var l = (s + n - 1) / n
    var r = s + 1
    while (r > l + 1) {
        val mid = (l + r) / 2
//        println("$mid: ${check(mid)}")
        if (check(mid)) {
            l = mid
        } else {
            r = mid
        }
    }
    println(l)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}