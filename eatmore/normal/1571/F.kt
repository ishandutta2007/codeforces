import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

fun solve() {
    val n = scanInt()
    val m = scanInt()
    val k = IntArray(n)
    val t = IntArray(n)
    var ksum = 0
    for (i in 0 until n) {
        k[i] = scanInt()
        t[i] = scanInt()
        ksum += k[i]
    }
    if (ksum > m) {
        out.print(-1)
        return
    }
    val ans = IntArray(n)
    Arrays.fill(ans, -1)
    var cur = 0
    for (i in 0 until n) {
        if (t[i] == 1) {
            ans[i] = cur
            cur += k[i]
        }
    }
    ksum -= cur
    val odd = (m - cur) / 2
    val even = (m - cur + 1) / 2
    val min = Math.max(0, ksum - odd)
    val max = Math.min(even, ksum)
    val back = IntArray(max + 1)
    Arrays.fill(back, -1)
    back[0] = -2
    for (i in 0 until n) {
        if (t[i] == 1) {
            continue
        }
        val ck = k[i]
        for (j in max - ck downTo 0) {
            if (back[j] != -1 && back[j + ck] == -1) {
                back[j + ck] = i
            }
        }
    }
    var i = min
    while (i <= max) {
        if (back[i] != -1) {
            var cur1 = cur
            while (i != 0) {
                ans[back[i]] = cur1
                cur1 += 2 * k[back[i]]
                i -= k[back[i]]
            }
            var cur2 = cur + 1
            i = 0
            while (i < n) {
                if (ans[i] < 0) {
                    ans[i] = cur2
                    cur2 += 2 * k[i]
                }
                out.print("" + (ans[i] + 1) + " ")
                i++
            }
            return
        }
        i++
    }
    out.print(-1)
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