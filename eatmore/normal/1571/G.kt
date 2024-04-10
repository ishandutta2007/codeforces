import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

fun sort(a: IntArray, n: Int, cmp: IntComparator) {
    if (n == 0) {
        return
    }
    for (i in 1 until n) {
        var j = i
        val ca = a[i]
        do {
            val nj = j - 1 shr 1
            val na = a[nj]
            if (cmp.compare(na, ca) >= 0) {
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
            j += if (cmp.compare(a[j + 1], a[j + 2]) < 0) 2 else 1
        }
        if ((j shl 1) + 2 == i) {
            j = (j shl 1) + 1
        }
        var na = a[i]
        a[i] = ca
        ca = na
        while (j != 0 && cmp.compare(a[j], ca) < 0) {
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

fun getMax(fenwick: LongArray, i: Int): Long {
    var i = i
    var res = fenwick[i]
    while (true) {
        i = (i and (i + 1)) - 1
        if (i < 0) {
            break
        }
        res = Math.max(res, fenwick[i])
    }
    return res
}

fun updateMax(fenwick: LongArray, i: Int, v: Long) {
    var i = i
    fenwick[i] = Math.max(fenwick[i], v)
    while (true) {
        i = i or (i + 1)
        if (i >= fenwick.size) {
            break
        }
        fenwick[i] = Math.max(fenwick[i], v)
    }
}

fun solve() {
    val n = scanInt()
    val m = scanInt()
    val a = IntArray(300000)
    val b = IntArray(300000)
    val c = IntArray(300000)
    var cnt = 0
    for (i in 0 until n) {
        val k = scanInt()
        for (j in 0 until k) {
            a[cnt + j] = scanInt()
        }
        for (j in 0 until k) {
            b[cnt + j] = scanInt()
        }
        for (j in 0 until k) {
            c[cnt + j] = i
        }
        cnt += k
    }
    val idx = IntArray(cnt)
    for (i in 0 until cnt) {
        idx[i] = i
    }
    sort(idx, cnt, object : IntComparator {
        override fun compare(o1: Int, o2: Int): Int {
            return if (b[o1] != b[o2]) {
                b[o1] - b[o2]
            } else {
                c[o2] - c[o1]
            }
        }
    })
    var ans: Long = 0
    val tree = LongArray(n + m + 1)
    for (i in idx) {
        if (b[i] + c[i] < m) {
            continue
        }
        val cans = a[i] + getMax(tree, n + m - 1 - (b[i] + c[i]))
        ans = Math.max(ans, cans)
        updateMax(tree, n + m - (b[i] + c[i]), cans)
    }
    out.print(ans)
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

interface IntComparator {
    fun compare(o1: Int, o2: Int): Int
}