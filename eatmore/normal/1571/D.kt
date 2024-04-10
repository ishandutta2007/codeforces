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
    val m = scanInt()
    val cntF = IntArray(n)
    val cntL = IntArray(n)
    val choice = IntArray(m - 1)
    val myF = scanInt() - 1
    val myL = scanInt() - 1
    for (i in 0 until m - 1) {
        val f = scanInt() - 1
        val l = scanInt() - 1
        ++cntF[f]
        ++cntL[l]
        choice[i] = f * n + l
    }
    sort(choice, m - 1)
    var p = 0
    var ans = 0
    for (f in 0 until n) {
        for (l in 0 until n) {
            var cans = cntF[f] + cntL[l]
            while (p < m - 1 && choice[p] == f * n + l) {
                ++p
                --cans
            }
            if (f != myF && l != myL && f != l) {
                ans = Math.max(ans, cans)
            }
        }
    }
    out.print(ans + 1)
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