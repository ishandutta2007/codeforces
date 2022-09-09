import kotlin.Throws
import java.lang.Math
import java.io.IOException
import java.util.StringTokenizer
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.lang.Exception

fun solve() {
    val s = scanString()
    val n = s.length
    var n0 = 0
    var n1 = 0
    val p0 = IntArray(n)
    val p1 = IntArray(n)
    val p0i = IntArray(n)
    val p1i = IntArray(n)
    for (i in 0 until n) {
        p0[i] = n0
        p1[i] = n1
        if (s[i] == '0') {
            p0i[n0] = i
            ++n0
        } else {
            p1i[n1] = i
            ++n1
        }
    }
    for (k in 1..n) {
        var pos = 0
        var ans = 0
        while (pos < n) {
            ++ans
            val np0 = p0[pos] + k
            val np1 = p1[pos] + k
            if (np0 >= n0 || np1 >= n1) {
                break
            }
            pos = Math.max(p0i[np0], p1i[np1])
        }
        out.print("$ans ")
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