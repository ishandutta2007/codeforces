import java.io.BufferedReader
import kotlin.math.max

private const val START = 0
private const val PEAK = 1
private const val END = 2

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val m = br.readInt().toLong()
        val xs = LongArray(n)
        val intensities = LongArray(n)
        val sweep = mutableListOf<RainEvent>()
        for (i in 0 until n) {
            xs[i] = br.readInt().toLong()
            intensities[i] = br.readInt().toLong()
            sweep += RainEvent(START, xs[i] - intensities[i])
            sweep += RainEvent(PEAK, xs[i])
            sweep += RainEvent(END, xs[i] + intensities[i])
        }

        var sumNeeded = Long.MIN_VALUE
        var difNeeded = Long.MIN_VALUE
        sweep.sortBy { it.x }

        var curDelt = 0L
        var prevX = Long.MIN_VALUE
        var curIntensity = 0L
        for ((type, x) in sweep) {
            curIntensity += (x - prevX) * curDelt
            when (type) {
                START -> curDelt++
                PEAK -> {
                    curDelt -= 2
                    if (curIntensity > m) {
                        sumNeeded = max(sumNeeded, curIntensity - m + x)
                        difNeeded = max(difNeeded, curIntensity - m - x)
                    }
                }
                END -> curDelt++
            }
            prevX = x
        }
        for(i in 0 until n) {
            if(intensities[i] + xs[i] >= sumNeeded && intensities[i] - xs[i] >= difNeeded) {
                bw.append('1')
            } else {
                bw.append('0')
            }
        }
        bw.appendLine()

    }
    bw.flush()
}

private data class RainEvent(val type: Int, val x: Long)

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