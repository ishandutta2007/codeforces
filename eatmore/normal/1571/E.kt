import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

fun solve() {
    val tests = scanInt()
    var dyn = IntArray(8)
    var ndyn = IntArray(8)
    for (test in 0 until tests) {
        val n = scanInt()
        val s = scanString()
        val t = scanString()
        val start = (if (s[0] == ')') 1 else 0) + (if (s[1] == ')') 2 else 0) + if (s[2] == ')') 4 else 0
        for (i in 0..7) {
            dyn[i] = Integer.bitCount(i xor start)
        }
        for (i in 0 until n - 3) {
            val next = if (s[i + 3] == ')') 8 else 0
            val valid = if (t[i] == '1') 0x1400 else 0xffff
            Arrays.fill(ndyn, Int.MAX_VALUE / 2)
            for (j in 0..15) {
                if (valid and (1 shl j) != 0) {
                    ndyn[j shr 1] = Math.min(ndyn[j shr 1], dyn[j and 7] + if (j and 8 == next) 0 else 1)
                }
            }
            val tt = dyn
            dyn = ndyn
            ndyn = tt
        }
        var ans = Int.MAX_VALUE / 2
        for (i in 0..7) {
            ans = Math.min(ans, dyn[i])
        }
        out.println(if (ans == Int.MAX_VALUE / 2) -1 else ans)
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