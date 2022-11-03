import java.io.BufferedReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()

    repeat(t) {
        val xs = LongArray(4)
        val ys = LongArray(4)

        fun solve(ul: Int, ur: Int, bl: Int, br: Int): Long {
            val highUpperY = max(ys[ul], ys[ur])
            val lowUpperY = min(ys[ul], ys[ur])

            val highLowerY = max(ys[bl], ys[br])
            val lowLowerY = min(ys[bl], ys[br])

            val highLeftX = max(xs[bl], xs[ul])
            val lowLeftX = min(xs[bl], xs[ul])

            val highRightX = max(xs[ur], xs[br])
            val lowRightX = min(xs[ur], xs[br])

            val baseCost =
                (highUpperY + highLowerY + highLeftX + highRightX) - (lowUpperY + lowLowerY + lowLeftX + lowRightX)


            val lowXDif = lowRightX - highLeftX
            val highXDif = highRightX - lowLeftX
            val lowYDif = lowUpperY - highLowerY
            val highYDif = highUpperY - lowLowerY
            return if (highXDif < lowYDif) {
                baseCost + (lowYDif - highXDif) * 2
            } else if (highYDif < lowXDif) {
                baseCost + (lowXDif - highYDif) * 2
            } else {
                baseCost
            }

        }

        for (i in 0 until 4) {
            xs[i] = br.readInt().toLong()
            ys[i] = br.readInt().toLong()
        }
        var ans = Long.MAX_VALUE
        for (first in 0 until 4) {
            for (second in 0 until 4) {
                if (first == second) continue
                for (third in 0 until 4) {
                    if (first == third || second == third) continue
                    val fourth = 6 - first - second - third
                    ans = min(ans, solve(first, second, third, fourth))
                }
            }
        }
        bw.appendLine("$ans")
    }
    bw.flush()
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