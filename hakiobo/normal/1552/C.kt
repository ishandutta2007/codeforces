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
        val used = BooleanArray(n shl 1)
        val xs = IntArray(n)
        val ys = IntArray(n) { idx ->
            if (idx < k) {
                val a = br.readInt() - 1
                val b = br.readInt() - 1
                used[a] = true
                used[b] = true
                xs[idx] = min(a, b)
                max(a, b)
            } else {
                -1
            }
        }
        var idx = 0
        for (x in k until n) {
            while (used[idx]) {
                idx++
            }
            xs[x] = idx
            used[idx] = true
        }
        for (x in k until n) {
            while (used[idx]) {
                idx++
            }
            ys[x] = idx
            used[idx] = true
        }
        var numIntersections = 0
        for (a in 0 until n) {
            for (b in a + 1 until n) {
                val x1 = xs[a]
                val x2 = xs[b]
                val y1 = ys[a]
                val y2 = ys[b]
                if (y1 > x2 && y2 > x1) {
                    if (x1 > x2 && y1 > y2) {
                        numIntersections++
                    } else if (x1 < x2 && y1 < y2) {
                        numIntersections++
                    }
                }
            }
        }
        sb.appendLine(numIntersections)

    }
    print(sb)
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