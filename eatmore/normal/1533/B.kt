import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

fun solve() {
    val tests = scanInt()
    for (test in 0 until tests) {
        val n = scanInt()
        var prev = -1
        var ans = false
        for (i in 0 until n) {
            val cur = scanInt()
            if (prev >= 0 && cur - prev and 1 == 0) {
                ans = true
            }
            prev = cur
        }
        out.println(if (ans) "YES" else "NO")
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