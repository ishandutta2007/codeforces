import java.io.BufferedReader

data class Wire(val a: Long, val b: Long, val c: Long) : Comparable<Wire> {
    fun canonical(): Wire {
        val g = gcd(gcd(a, b), c)
        return if (a < 0) {
            Wire(-a / g, -b / g, -c / g)

        } else if (a == 0L && b < 0) {
            Wire(-a / g, -b / g, -c / g)

        } else {
            Wire(a / g, b / g, c / g)
        }
    }

    override fun compareTo(other: Wire): Int {
        return if (a.compareTo(other.a) != 0) {
            a.compareTo(other.a)
        } else if (b.compareTo(other.b) != 0) {
            b.compareTo(other.b)
        } else {
            c.compareTo(other.c)
        }
    }

    companion object {
        fun gcd(p: Long, q: Long): Long {
            return if (p < 0) gcd(-p, q)
            else if (q < 0) gcd(p, -q)
            else if (p == 0L) q
            else if (q == 0L) p
            else if (p and 1 == 0L && q and 1 == 0L) gcd(p shr 1, q shr 1) shl 1
            else if (p and 1 == 0L) gcd(p shr 1, q)
            else if (q and 1 == 0L) gcd(p, q shr 1)
            else if (p > q) gcd((p - q) shr 1, q)
            else gcd(p, (q - p) shr 1)
        }
    }
}

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val xs = LongArray(n)
    val ys = LongArray(n) { idx ->
        xs[idx] = br.readInt().toLong()
        br.readInt().toLong()
    }
    val wires = mutableListOf<Wire>()
    for (u in 0 until n) {
        for (v in u + 1 until n) {
            val dx = xs[u] - xs[v]
            val dy = ys[v] - ys[u]

            wires += Wire(dx, dy, dy * xs[u] + dx * ys[u]).canonical()
        }
    }
    wires.sort()
    var ans = 0L
    var dif = 0L
    var cur = 1L
    for (x in 1 until wires.size) {
        if (wires[x].compareTo(wires[x - 1]) != 0) {
            if (wires[x].a == wires[x - 1].a && wires[x].b == wires[x - 1].b) {
                cur++
            } else {
                ans += cur * dif
                dif += cur
                cur = 1
            }
        }
    }
    ans += dif * cur
    print(ans)
}

private const val SPACE_INT = ' '.toInt()
private const val ZERO_INT = '0'.toInt()
private const val NL_INT = '\n'.toInt()

private fun BufferedReader.readInt(): Int {
    var ret = read()
    while (ret <= SPACE_INT) {
        ret = read()
    }
    val neg = ret == '-'.toInt()
    if (neg) {
        ret = read()
    }
    ret -= ZERO_INT
    var read = read()
    while (read >= ZERO_INT) {
        ret *= 10
        ret += read - ZERO_INT
        read = read()
    }

    while (read <= SPACE_INT && read != -1 && read != NL_INT) {
        mark(1)
        read = read()
    }
    if (read > SPACE_INT) {
        reset()
    }
    return if (neg) -ret else ret
}