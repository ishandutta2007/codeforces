import java.util.Arrays
import java.util.StringTokenizer
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.lang.AssertionError

const val MOD = 998244353
fun add(a: Int, b: Int): Int {
    val res = a + b
    return if (res >= MOD) res - MOD else res
}

fun mul(a: Int, b: Int): Int {
    val res = (a.toLong() * b % MOD).toInt()
    return if (res < 0) res + MOD else res
}

fun amul(r: IntArray, a: IntArray, b: IntArray) {
    for (i in 0..8191) {
        r[i] = mul(a[i], b[i])
    }
}

fun solve() {
    val n = scanInt()
    val m = scanInt()
    val w = IntArray(n)
    val cnt = IntArray(n)
    for (i in 0 until n) {
        w[i] = scanInt()
    }
    val buf = IntArray(8192)
    val tree = Tree(n)
    for (qq in 0 until m) {
        val type = scanInt()
        if (type <= 2) {
            val i = scanInt() - 1
            var c = scanInt()
            if (type == 2) {
                c = -c
            }
            tree[i, w[i]] = c.let { cnt[i] += it; cnt[i] }
        } else {
            val l = scanInt() - 1
            val r = scanInt()
            val k = scanInt()
            Arrays.fill(buf, 1)
            tree[l, r, buf]
            FFTPrime.fftI(buf, 13, 0)
            var ans = 0
            for (i in 1..k) {
                ans = add(ans, buf[i])
            }
            out.println(ans)
        }
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

internal object FFTPrime {
    const val MOD = 998244353
    const val IDENT = 503245988
    const val MAXBITS = 23
    const val GEN = 507547112
    const val MULFIX = 479173089
    fun mul(a: Int, b: Int): Int {
        var res = a.toLong() * b
        var low = res and 0x7fffff
        res = (res shr 23) + MOD + low + (low shl 3) - (low shl 7)
        low = res and 0x7fffff
        res = (res shr 23) + low + (low shl 3) - (low shl 7)
        if (res < 0) {
            res += MOD.toLong()
        }
        return res.toInt()
    }

    fun add(a: Int, b: Int): Int {
        var res = a + b
        if (res - MOD >= 0) {
            res -= MOD
        }
        return res
    }

    fun sub(a: Int, b: Int): Int {
        var res = a - b
        if (res < 0) {
            res += MOD
        }
        return res
    }

    var GENPOWS = IntArray(0)
    var GENPOWSI = IntArray(0)
    fun checkBits(bits: Int) {
        if (bits < 0 || bits > MAXBITS) {
            throw AssertionError()
        }
        if (bits != 0 && GENPOWS.size < 1 shl bits - 1) {
            GENPOWS = IntArray(1 shl bits - 1)
            GENPOWSI = IntArray(1 shl bits - 1)
            var gen = GEN
            for (i in bits until MAXBITS) {
                gen = mul(gen, gen)
            }
            var pow = IDENT
            for (i in 0 until (1 shl (bits - 1))) {
                GENPOWS[Integer.reverse(i) ushr 32 - (bits - 1)] = pow
                GENPOWSI[Integer.reverse(-i) ushr 32 - (bits - 1)] = MOD - pow
                pow = mul(pow, gen)
            }
            GENPOWSI[0] = IDENT
        }
    }

    fun fft(arr: IntArray, bits: Int) {
        checkBits(bits)
        val n = 1 shl bits
        val p = GENPOWS
        var bit = bits - 1
        while (bit > 1) {
            var iStart = 0
            while (iStart != n) {
                val iMid = iStart + (1 shl bit - 2)
                val iEnd = iStart + (1 shl bit - 1)
                val q = iStart shr bit
                val r = iStart shr bit - 1
                val u = p[q]
                val v = p[q + 1]
                val w = p[r]
                val x = p[r + 1]
                val y = p[r + 2]
                val z = p[r + 3]
                for (i in iStart until iMid) {
                    val j = i xor (1 shl bit - 1)
                    val k = i xor (1 shl bit)
                    val l = k xor (1 shl bit - 1)
                    val a = arr[i]
                    val b = arr[j]
                    val c = arr[k]
                    val d = arr[l]
                    val e = add(a, c)
                    val f = mul(b + d, u)
                    val g = sub(a, c)
                    val h = mul(b - d + MOD, v)
                    arr[i] = add(e, f)
                    arr[j] = sub(e, f)
                    arr[k] = add(g, h)
                    arr[l] = sub(g, h)
                }
                for (i in iMid until iEnd) {
                    val j = i xor (1 shl bit - 1)
                    val k = i xor (1 shl bit)
                    val l = k xor (1 shl bit - 1)
                    val a = arr[i]
                    val b = arr[j]
                    val c = arr[k]
                    val d = arr[l]
                    val e = add(a, c)
                    val f = mul(b + d, u)
                    val g = sub(a, c)
                    val h = mul(b - d + MOD, v)
                    arr[i] = mul(e + f, w)
                    arr[j] = mul(e - f + MOD, x)
                    arr[k] = mul(g + h, y)
                    arr[l] = mul(g - h + MOD, z)
                }
                iStart += 1 shl bit + 1
            }
            bit -= 2
        }
        if (bits and 1 != 0) {
            var i = 0
            while (i != n) {
                val a = arr[i]
                val b = arr[i + 1]
                arr[i] = add(a, b)
                arr[i + 1] = sub(a, b)
                i += 2
            }
        } else if (bits != 0) {
            var i = 0
            while (i != n) {
                val q = i shr 1
                val u = p[q]
                val v = p[q + 1]
                val a = arr[i]
                val b = arr[i + 1]
                val c = arr[i + 2]
                val d = arr[i + 3]
                val e = add(a, c)
                val f = mul(b + d, u)
                val g = sub(a, c)
                val h = mul(b - d + MOD, v)
                arr[i] = add(e, f)
                arr[i + 1] = sub(e, f)
                arr[i + 2] = add(g, h)
                arr[i + 3] = sub(g, h)
                i += 4
            }
        }
    }

    fun fftI(arr: IntArray, bits: Int, fixes: Int) {
        checkBits(bits)
        var m = IDENT
        val half = mul(MOD + 1 ushr 1, MULFIX)
        for (i in 0 until bits) {
            m = mul(m, half)
        }
        for (i in 0 until fixes) {
            m = mul(m, MULFIX)
        }
        val n = 1 shl bits
        val p = GENPOWSI
        var bit = 0
        while (bit < bits - 2) {
            var iStart = 0
            while (iStart != n) {
                val iEnd = iStart + (1 shl bit)
                val q = iStart shr bit + 1
                val r = iStart shr bit + 2
                val u = p[q]
                val v = p[q + 1]
                val w = p[r]
                for (i in iStart until iEnd) {
                    val j = i xor (1 shl bit)
                    val k = i xor (1 shl bit + 1)
                    val l = k xor (1 shl bit)
                    val a = arr[i]
                    val b = arr[j]
                    val c = arr[k]
                    val d = arr[l]
                    val e = add(a, b)
                    val f = mul(a - b + MOD, u)
                    val g = add(c, d)
                    val h = mul(c - d + MOD, v)
                    arr[i] = add(e, g)
                    arr[j] = add(f, h)
                    arr[k] = mul(e - g + MOD, w)
                    arr[l] = mul(f - h + MOD, w)
                }
                iStart += 1 shl bit + 2
            }
            bit += 2
        }
        if (bits and 1 != 0) {
            for (i in 0 until (1 shl (bits - 1))) {
                val j: Int = i xor (1 shl bits - 1)
                val a = arr[i]
                val b = arr[j]
                arr[i] = mul(a + b, m)
                arr[j] = mul(a - b + MOD, m)
            }
        } else if (bits != 0) {
            val v = p[1]
            for (i in 0 until (1 shl (bits - 2))) {
                val j: Int = i xor (1 shl bits - 2)
                val k: Int = i xor (1 shl bits - 1)
                val l = k xor (1 shl bits - 2)
                val a = arr[i]
                val b = arr[j]
                val c = arr[k]
                val d = arr[l]
                val e = add(a, b)
                val f = sub(a, b)
                val g = add(c, d)
                val h = mul(c - d + MOD, v)
                arr[i] = mul(e + g, m)
                arr[j] = mul(f + h, m)
                arr[k] = mul(e - g + MOD, m)
                arr[l] = mul(f - h + MOD, m)
            }
        } else {
            arr[0] = mul(arr[0], m)
        }
    }
}

internal class Tree(val n: Int) {
    val t: Array<IntArray>
    fun fix(i: Int) {
        amul(t[i - 1], t[(i shl 1) - 1], t[i shl 1])
    }

    operator fun get(l: Int, r: Int, v: IntArray) {
        var l = l
        var r = r
        l += n
        r += n
        while (l != r) {
            if (l and 1 != 0) {
                amul(v, v, t[l++ - 1])
            }
            if (r and 1 != 0) {
                amul(v, v, t[--r - 1])
            }
            l = l ushr 1
            r = r ushr 1
        }
    }

    operator fun set(i: Int, w: Int, c: Int) {
        var i = i
        val v = t[n.let { i += it; i } - 1]
        Arrays.fill(v, 0)
        for (j in 0..c) {
            v[j * w] = 1
        }
        FFTPrime.fft(v, 13)
        i = i shr 1
        while (i != 0) {
            fix(i)
            i = i shr 1
        }
    }

    init {
        t = Array(2 * n - 1) { IntArray(8192) }
        for (a in t) {
            Arrays.fill(a, 1)
        }
    }
}