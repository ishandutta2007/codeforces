import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

fun sortBy(a: IntArray, n: Int, v: IntArray) {
    if (n == 0) {
        return
    }
    for (i in 1 until n) {
        var j = i
        val ca = a[i]
        val cv = v[ca]
        do {
            val nj = j - 1 shr 1
            val na = a[nj]
            if (cv <= v[na]) {
                break
            }
            a[j] = na
            j = nj
        } while (j != 0)
        a[j] = ca
    }
    var ca = a[0]
    for (i in n - 1 downTo 1) {
        var j = 0
        while ((j shl 1) + 2 + Int.MIN_VALUE < i + Int.MIN_VALUE) {
            j = j shl 1
            j += if (v[a[j + 2]] > v[a[j + 1]]) 2 else 1
        }
        if ((j shl 1) + 2 == i) {
            j = (j shl 1) + 1
        }
        var na = a[i]
        a[i] = ca
        ca = na
        val cv = v[ca]
        while (j != 0 && v[a[j]] < cv) {
            j = j - 1 shr 1
        }
        while (j != 0) {
            na = a[j]
            a[j] = ca
            ca = na
            j = j - 1 shr 1
        }
    }
    a[0] = ca
}

fun solve() {
    val tests = scanInt()
    test@ for (test in 0 until tests) {
        val n = scanInt()
        val l = IntArray(n)
        val r = IntArray(n)
        val idxL = IntArray(n)
        val idxR = IntArray(n)
        for (i in 0 until n) {
            l[i] = scanInt()
            idxL[i] = i
        }
        for (i in 0 until n) {
            r[i] = scanInt()
            idxR[i] = i
        }
        sortBy(idxL, n, l)
        sortBy(idxR, n, r)
        var min = 0
        var max = Int.MAX_VALUE
        for (i in 0 until n) {
            min = Math.max(min, l[idxL[i]] - i)
            max = Math.min(max, r[idxR[i]] + n - 1 - i)
        }
        if (min > max) {
            out.println(-1)
            continue
        }
        val q = PriorityQueue<Token>()
        var p = 0
        val ans = IntArray(n)
        val start = min
        for (i in 0 until n) {
            while (p < n && l[idxL[p]] <= start + i) {
                val c = idxL[p++]
                q.add(Token(c, r[c]))
            }
            if (q.isEmpty()) {
                out.println(-1)
                continue@test
            }
            val cur = q.remove()
            if (cur.pos < start + i) {
                out.println(-1)
                continue@test
            }
            ans[i] = cur.i
        }
        out.println(start)
        for (i in 0 until n) {
            out.print(ans[i] + 1)
            out.print(' ')
        }
        out.println()
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

internal class Token(val i: Int, val pos: Int) : Comparable<Token> {
    override fun compareTo(o: Token): Int {
        return pos - o.pos
    }
}