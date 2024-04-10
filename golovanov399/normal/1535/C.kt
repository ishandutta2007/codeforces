import kotlin.math.*

fun solve() {
    val s = readLine()!!
    val cnt = mutableListOf(0, 0)
    var ans = 0L
    var r = 0
    for (l in s.indices) {
        while (r < s.length && cnt.minOrNull()!! == 0) {
            if (s[r] == '0') {
                cnt[r % 2] += 1
            } else if (s[r] == '1') {
                cnt[(r + 1) % 2] += 1
            }
            r += 1
        }
//        println("$l $r: $cnt")
        ans += r - l - (if (cnt.minOrNull()!! > 0) 1 else 0)
        if (s[l] == '0') {
            cnt[l % 2] -= 1
        } else if (s[l] == '1') {
            cnt[(l + 1) % 2] -= 1
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