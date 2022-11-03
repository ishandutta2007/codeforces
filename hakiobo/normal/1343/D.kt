import java.io.BufferedReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val k = br.readInt()
        val lows = Fenwick(k)
        val highs = Fenwick(k)
        val sums = IntArray(2 * k + 1)
        val nums = IntArray(n) {
            br.readInt()
        }
        for (x in 0 until (n shr 1)) {
            val a = nums[x]
            val b = nums[n - x - 1]
            lows.add(min(a, b), 1)
            highs.add(max(a, b), 1)
            sums[a + b]++
        }
        var best = n
        for (x in 2..k) {
            val o = n - lows.get(x - 1) - sums[x]
            best = best.coerceAtMost(o)
        }
        for (x in (k + 1)..(2 * k)) {
            val o = n - highs.get(x - k, k) - sums[x]
            best = best.coerceAtMost(o)
        }
        sb.append(best).append('\n')
    }
    print(sb)
}


private class Fenwick(val size: Int) {
    private val ary = IntArray(size)

    fun add(idx: Int, v: Int) {
        var k = idx
        while (k <= size) {
            ary[k - 1] += v
            k += k and -k
        }
    }

    fun set(idx: Int, v: Int) {
        add(idx, v - get(idx, idx))
    }

    fun get(idx: Int): Int {
        var k = idx
        var r = 0
        while (k > 0) {
            r += ary[k - 1]
            k -= k and -k
        }
        return r
    }

    fun get(a: Int, b: Int): Int {
        return get(b) - get(a - 1)
    }
}

private const val SPACE_INT = ' '.toInt()
private const val ZERO_INT = '0'.toInt()
private const val NL_INT = '\n'.toInt()

@Suppress("DuplicatedCode")
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