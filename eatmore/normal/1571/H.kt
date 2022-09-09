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

const val MOD = 998244353
fun add(a: Int, b: Int): Int {
    val res = a + b
    return if (res >= MOD) res - MOD else res
}

fun sub(a: Int, b: Int): Int {
    val res = a - b
    return if (res < 0) res + MOD else res
}

fun mul(a: Int, b: Int): Int {
    val res = (a.toLong() * b % MOD).toInt()
    return if (res < 0) res + MOD else res
}

fun pow(a: Int, e: Int): Int {
    if (e == 0) {
        return 1
    }
    var r = a
    for (i in 30 - Integer.numberOfLeadingZeros(e) downTo 0) {
        r = mul(r, r)
        if (e and (1 shl i) != 0) {
            r = mul(r, a)
        }
    }
    return r
}

fun inv(a: Int): Int {
    return pow(a, MOD - 2)
}

fun solve() {
    val n = scanInt()
    val a = 2 * scanInt()
    val b = 2 * scanInt()
    val x = IntArray(n + 2)
    val y = IntArray(n + 2)
    val xpy = IntArray(n)
    val xmy = IntArray(n)
    val p = IntArray(n)
    val iii = inv(1000000)
    for (i in 0 until n) {
        x[i] = scanInt() * 2
        y[i] = scanInt() * 2
        xpy[i] = x[i] + y[i]
        xmy[i] = x[i] - y[i]
        p[i] = mul(scanInt(), iii)
    }
    x[n] = 0
    x[n + 1] = a
    y[n] = 0
    y[n + 1] = b
    sort(x, n + 2)
    sort(y, n + 2)
    val idxXpy = IntArray(n)
    val idxXmy = IntArray(n)
    for (i in 0 until n) {
        idxXmy[i] = i
        idxXpy[i] = idxXmy[i]
    }
    sortBy(idxXpy, n, xpy)
    sortBy(idxXmy, n, xmy)
    var bx = 0
    for (i in 0 until n + 1) {
        if (x[i + 1] > x[i]) {
            ++bx
        }
    }
    var by = 0
    for (i in 0 until n + 1) {
        if (y[i + 1] > y[i]) {
            ++by
        }
    }
    var ans = bx * by
    val ppp = IntArray(n)
    Arrays.fill(ppp, -1)
    run {
        var i = 0
        var j: Int
        while (i < n) {
            val v = xpy[idxXpy[i]]
            j = i + 1
            while (j < n && xpy[idxXpy[j]] == v) {
                j++
            }
            var pp = 1
            for (k in i until j) {
                pp = mul(pp, sub(1, p[idxXpy[k]]))
            }
            pp = sub(1, pp)
            ppp[i] = pp
            var c = 0
            for (ii in 0 until n + 1) {
                for (jj in 0 until n + 1) {
                    if (x[ii + 1] > x[ii] && y[jj + 1] > y[jj] && x[ii] + y[jj] < v && x[ii + 1] + y[jj + 1] > v) {
                        ++c
                    }
                }
            }
            ans = add(ans, mul(pp, c))
            i = j
        }
    }
    val ppm = IntArray(n)
    Arrays.fill(ppm, -1)
    run {
        var i = 0
        var j: Int
        while (i < n) {
            val v = xmy[idxXmy[i]]
            j = i + 1
            while (j < n && xmy[idxXmy[j]] == v) {
                j++
            }
            var pp = 1
            for (k in i until j) {
                pp = mul(pp, sub(1, p[idxXmy[k]]))
            }
            pp = sub(1, pp)
            ppm[i] = pp
            var c = 0
            for (ii in 0 until n + 1) {
                for (jj in 0 until n + 1) {
                    if (x[ii + 1] > x[ii] && y[jj + 1] > y[jj] && x[ii] - y[jj + 1] < v && x[ii + 1] - y[jj] > v) {
                        ++c
                    }
                }
            }
            ans = add(ans, mul(pp, c))
            i = j
        }
    }
    for (i in 0 until n) {
        if (ppp[i] < 0) {
            continue
        }
        for (j in 0 until n) {
            if (ppm[j] < 0) {
                continue
            }
            val xxpy = xpy[idxXpy[i]]
            val xxmy = xmy[idxXmy[j]]
            val xx = xxpy + xxmy shr 1
            val yy = xxpy - xxmy shr 1
            if (xx <= 0 || xx >= a || yy <= 0 || yy >= b) {
                continue
            }
            val ii = Arrays.binarySearch(x, xx)
            val jj = Arrays.binarySearch(y, yy)
            if (ii >= 0 || jj >= 0) {
                continue
            }
            val pp = mul(ppp[i], ppm[j])
            ans = add(ans, pp)
        }
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