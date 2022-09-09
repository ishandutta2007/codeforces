import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

fun solve() {
    val n = scanInt()
    val m = scanInt()
    val cnts: MutableMap<String, Val> = HashMap()
    for (i in 0 until n) {
        val s = scanString()
        var v = cnts[s]
        if (v == null) {
            v = Val()
            cnts[s] = v
            v.q = -1
        }
        ++v.cnt
    }
    val q = scanInt()
    for (qq in 0 until q) {
        val s = scanString()
        var ans = 0
        for (i in 0..m) {
            val v = cnts[s.substring(0, i) + s.substring(i + 1)]
            if (v != null && v.q != qq) {
                ans += v.cnt
                v.q = qq
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

internal class Val {
    var cnt = 0
    var q = 0
}