import kotlin.Throws
import java.util.Arrays
import java.lang.Math
import java.io.IOException
import java.util.StringTokenizer
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.lang.Exception

fun solve() {
    val tests = scanInt()
    for (test in 0 until tests) {
        val n = scanInt()
        val a = IntArray(n)
        val p1 = IntArray(n)
        val p2 = IntArray(n)
        Arrays.fill(p1, -1)
        Arrays.fill(p2, -1)
        for (i in 0 until n) {
            a[i] = scanInt() - 1
            (if (p1[a[i]] < 0) p1 else p2)[a[i]] = i
        }
        val tree = IntMaxTree(n)
        var ans = 1
        for (i in 0 until n) {
            val v = a[i]
            if (p2[v] < 0 || p2[v] == i) {
                continue
            }
            val cans = Math.max(0, tree.getMax(p2[v], n)) + 1
            tree[p2[v]] = cans
            ans = Math.max(ans, 2 * cans + if (p2[v] == i + 1) 0 else 1)
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

internal class IntMaxTree(val n: Int) {
    val t: IntArray
    fun init(v: IntArray) {
        for (i in 0 until n) {
            t[n - 1 + i] = v[i]
        }
        for (i in n - 1 downTo 1) {
            t[i - 1] = Math.max(t[(i shl 1) - 1], t[i shl 1])
        }
    }

    operator fun get(i: Int): Int {
        return t[i + n - 1]
    }

    fun getMax(l: Int, r: Int): Int {
        var l = l
        var r = r
        var v = Int.MIN_VALUE
        l += n
        r += n
        while (l != r) {
            if (l and 1 != 0) {
                v = Math.max(v, t[l++ - 1])
            }
            if (r and 1 != 0) {
                v = Math.max(v, t[--r - 1])
            }
            l = l ushr 1
            r = r ushr 1
        }
        return v
    }

    operator fun set(i: Int, v: Int) {
        var i = i
        t[n.let { i += it; i } - 1] = v
        i = i shr 1
        while (i != 0) {
            t[i - 1] = Math.max(t[(i shl 1) - 1], t[i shl 1])
            i = i shr 1
        }
    }

    init {
        t = IntArray(2 * n - 1)
    }
}