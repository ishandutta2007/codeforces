import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

fun solve() {
    val tests = scanInt()
    for (test in 0 until tests) {
        val n = scanInt()
        val k = scanInt()
        val s = scanString()
        val gone = BooleanArray(n)
        var left = 0
        for (i in 0 until n) {
            if (s[i] == '1') {
                ++left
            }
        }
        var cur = 0
        var ans = 0
        while (left > 0) {
            gone[cur] = true
            ++ans
            if (s[cur] == '1') {
                --left
            }
            if (left == 0) {
                break
            }
            var i = 0
            while (i < k) {
                ++cur
                if (cur == n) {
                    cur = 0
                }
                if (gone[cur]) {
                    --i
                }
                i++
            }
        }
        out.println(ans)
    }
}

fun scanInt(): Int {
    return scanString().toInt()
}

fun scanLong(): Long {
    return scanString().toLong()
}

fun scanString(): String {
    var t = tok
    while (t == null || !t.hasMoreTokens()) {
        t = StringTokenizer(inp.readLine())
        tok = t
    }
    return t.nextToken()
}

val inp = BufferedReader(InputStreamReader(System.`in`))
val out = PrintWriter(System.out)
var tok: StringTokenizer? = null
fun main() {
    solve()
    inp.close()
    out.close()
}