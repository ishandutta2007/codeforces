import java.lang.System
import kotlin.Throws
import java.util.Arrays
import java.io.IOException
import java.util.StringTokenizer
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.lang.Exception

val trans0 = IntArray(16)
val trans1 = IntArray(16)
const val MOD = 998244353
fun add(a: Int, b: Int): Int {
    val res = a + b
    return if (res >= MOD) res - MOD else res
}

fun mul(a: Int, b: Int): Int {
    val res = (a.toLong() * b % MOD).toInt()
    return if (res < 0) res + MOD else res
}

fun mmul(r: IntArray, a: IntArray, b: IntArray) {
    for (i in 0..3) {
        for (j in 0..3) {
            var v = 0
            for (k in 0..3) {
                v = add(v, mul(a[i * 4 + k], b[k * 4 + j]))
            }
            r[i * 4 + j] = v
        }
    }
}

val t = IntArray(4)
fun vmul(v: IntArray, m: IntArray) {
    for (i in 0..3) {
        var vv = 0
        for (j in 0..3) {
            vv = add(vv, mul(m[4 * i + j], v[j]))
        }
        t[i] = vv
    }
    System.arraycopy(t, 0, v, 0, 4)
}

fun solve() {
    val n = scanInt()
    val q = scanInt()
    val a = BooleanArray(n - 1)
    for (i in 0 until n - 1) {
        a[i] = scanInt() == 0
    }
    val tree = Tree(n - 1)
    tree.init(a)
    val v = IntArray(4)
    for (qq in 0 until q) {
        val p = scanInt() - 1
        tree[n - p - 2] = true.let { a[p] = a[p] xor it; a[p] }
        Arrays.fill(v, 1)
        tree.pass(0, n - 1, v)
        var ans = 0
        for (i in 0..3) {
            ans = add(ans, v[i])
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
    for (i in 0..3) {
        for (j in 0..3) {
            (if (i <= j) trans1 else trans0)[(j + if (i <= j) 0 else 1) * 4 + i] = 1
        }
    }
    solve()
    inp.close()
    out.close()
}

internal class Tree(val n: Int) {
    val t: Array<IntArray>
    fun init(a: BooleanArray) {
        for (i in 0 until n) {
            System.arraycopy(if (a[n - i - 1]) trans1 else trans0, 0, t[n - 1 + i], 0, 16)
        }
        for (i in n - 1 downTo 1) {
            fix(i)
        }
    }

    fun fix(i: Int) {
        mmul(t[i - 1], t[i shl 1], t[(i shl 1) - 1])
    }

    fun pass(l: Int, r: Int, v: IntArray) {
        var l = l
        var r = r
        var i: Int
        l += n
        r += n
        i = 0
        while (l != r ushr i) {
            if (l and 1 != 0) {
                vmul(v, t[l++ - 1])
            }
            l = l ushr 1
            ++i
        }
        while (i != 0) {
            val p = r ushr --i
            if (p and 1 != 0) {
                vmul(v, t[p - 2])
            }
        }
    }

    operator fun set(i: Int, v: Boolean) {
        var i = i
        System.arraycopy(if (v) trans1 else trans0, 0, t[n.let { i += it; i } - 1], 0, 16)
        i = i shr 1
        while (i != 0) {
            fix(i)
            i = i shr 1
        }
    }

    init {
        t = Array(2 * n - 1) { IntArray(16) }
    }
}