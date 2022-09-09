import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

fun solve() {
    val tests = scanInt()
    for (test in 0 until tests) {
        val n = scanInt()
        var min = 0
        var max = Int.MAX_VALUE
        for (i in 0 until n) {
            val s = scanString()
            val t = scanString()
            var d = 0
            var j = 0
            val l = Math.min(s.length, t.length)
            while (j < l) {
                if (s[s.length - j - 1] != t[t.length - j - 1]) {
                    break
                }
                d = j + 1
                j++
            }
            if (scanInt() == 0) {
                min = Math.max(min, d + 1)
            } else {
                max = Math.min(max, d)
            }
        }
        if (min > max) {
            out.println(0)
        } else {
            out.println(max - min + 1)
            for (i in min..max) {
                out.print("$i ")
            }
            out.println()
        }
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