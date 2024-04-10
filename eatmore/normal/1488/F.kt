import kotlin.Throws
import java.io.IOException
import java.util.StringTokenizer
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.lang.Exception
import java.util.Arrays
import java.lang.Math
import java.lang.System

fun solve() {
    val n = scanInt()
    val c = IntArray(n)
    for (i in 0 until n) {
        c[i] = scanInt()
    }
    val tree = Tree(c)
    val q = scanInt()
    for (qq in 0 until q) {
        val l = scanInt() - 1
        val r = scanInt()
        out.print(tree.pass(n - r, n - l).toString() + " ")
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

internal class Tree(a: IntArray) {
    val n: Int
    val max: Array<IntArray?>
    val sum: Array<LongArray?>
    fun pass(l: Int, r: Int): Long {
        var l = l
        var r = r
        var v: Long = 0
        var m = 0
        var i: Int
        l += n
        r += n
        i = 0
        while (l != r ushr i) {
            if (l and 1 != 0) {
                val ii = l++ - 1
                var pp = Arrays.binarySearch(max[ii], m)
                if (pp < 0) {
                    pp = pp.inv()
                }
                val ll: Int = max[ii]!!.size
                v += m.toLong() * pp + sum[ii]!![ll] - sum[ii]!![pp]
                m = Math.max(m, max[ii]!![ll - 1])
            }
            l = l ushr 1
            ++i
        }
        while (i != 0) {
            val p = r ushr --i
            if (p and 1 != 0) {
                val ii = p - 2
                var pp = Arrays.binarySearch(max[ii], m)
                if (pp < 0) {
                    pp = pp.inv()
                }
                val ll: Int = max[ii]!!.size
                v += m.toLong() * pp + sum[ii]!![ll] - sum[ii]!![pp]
                m = Math.max(m, max[ii]!![ll - 1])
            }
        }
        return v
    }

    init {
        n = a.size
        max = arrayOfNulls(2 * n - 1)
        sum = arrayOfNulls(2 * n - 1)
        for (i in 0 until n) {
            max[n - 1 + i] = IntArray(1)
            max[n - 1 + i]!![0] = a[n - i - 1]
        }
        for (i in n - 2 downTo 0) {
            val l = max[(i shl 1) + 1]
            val r = max[(i shl 1) + 2]
            val ll = l!!.size
            max[i] = IntArray(ll + r!!.size)
            val v = max[i]
            System.arraycopy(l, 0, v, 0, ll)
            for (j in r.indices) {
                v!![j + ll] = Math.max(v[j + ll - 1], r[j])
            }
        }
        for (i in 0 until 2 * n - 1) {
            val v = max[i]
            sum[i] = LongArray(v!!.size + 1)
            val s = sum[i]
            for (j in v.indices) {
                s!![j + 1] = s[j] + v[j]
            }
        }
    }
}