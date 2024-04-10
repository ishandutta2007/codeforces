import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

fun sort(a: IntArray, n: Int) {
    if (n == 0) {
        return
    }
    for (i in 1 until n) {
        var j = i
        val ca = a[i]
        do {
            val nj = j - 1 shr 1
            val na = a[nj]
            if (ca <= na) {
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
            j += if (a[j + 2] > a[j + 1]) 2 else 1
        }
        if ((j shl 1) + 2 == i) {
            j = (j shl 1) + 1
        }
        var na = a[i]
        a[i] = ca
        ca = na
        while (j != 0 && a[j] < ca) {
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
    val n = scanInt()
    val a = IntArray(n)
    val b = IntArray(n + 1)
    for (i in 0 until n) {
        a[i] = scanInt()
    }
    for (i in 0 until n + 1) {
        b[i] = scanInt()
    }
    val m = scanInt()
    val c = IntArray(m)
    for (i in 0 until m) {
        c[i] = scanInt()
    }
    sort(a, n)
    sort(b, n + 1)
    val pans = IntArray(n + 1)
    pans[0] = Int.MIN_VALUE
    for (i in 0 until n) {
        pans[i + 1] = Math.max(pans[i], b[i] - a[i])
    }
    val sans = IntArray(n + 1)
    sans[n] = Int.MIN_VALUE
    for (i in n - 1 downTo 0) {
        sans[i] = Math.max(sans[i + 1], b[i + 1] - a[i])
    }
    for (i in 0 until m) {
        var p = Arrays.binarySearch(a, c[i])
        if (p < 0) {
            p = p.inv()
        }
        out.print(Math.max(Math.max(pans[p], b[p] - c[i]), sans[p]).toString() + " ")
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