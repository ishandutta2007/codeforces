import kotlin.Throws
import java.io.IOException
import java.util.StringTokenizer
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.lang.Exception

fun solve() {
    val tests = scanInt()
    for (test in 0 until tests) {
        val n = scanLong()
        val s = scanLong()
        var l: Long = 1
        var r = s
        while (l < r) {
            val m = l + r + 1 ushr 1
            var cur: Long = 0
            var c = m
            for (i in 0 until n) {
                if (c == 1L) {
                    cur += n - i
                    break
                }
                cur += c
                c = c + 1 shr 1
            }
            if (cur > s) {
                r = m - 1
            } else {
                l = m
            }
        }
        out.println(l)
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