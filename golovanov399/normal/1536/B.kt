import java.util.*
import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    val s = readLine()!!
    val strs = mutableListOf<String>()
    for (i in 0 until n) {
        for (j in 1..3) {
            if (i + j > n) {
                break
            }
            strs.add(s.substring(i, i + j))
        }
    }
    strs.sort()
    val dict = strs.distinct().sortedWith(compareBy({ it.length }, { it }))
//    println(dict)

    fun nextStr(s: String): String {
        var i = s.length - 1
        while (i >= 0 && s[i] == 'z') {
            i -= 1
        }
        return if (i < 0) {
            String(CharArray(s.length + 1) { 'a' })
        } else {
            s.take(i) + s[i].inc() + String(CharArray(s.length - 1 - i) { 'a' })
        }
    }

    var i = 0
    var cur = "a"
    while (i < dict.size && dict[i] == cur) {
        i += 1
        cur = nextStr(cur)
    }
    println(cur)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}