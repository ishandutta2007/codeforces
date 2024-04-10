import java.io.BufferedReader
import java.util.*
import kotlin.math.min
import kotlin.system.exitProcess

fun main() {
    val br = System.`in`.bufferedReader()
    var mode = -1
    var freq = -1
    var numQueries = 0
    fun query(low: Int, high: Int) {
        numQueries--
        val qSb = StringBuilder("? ").append(low + 1).append(' ').append(high + 1)
//        print("? ")
//        print(low + 1)
//        print(" ")
//        println(high + 1)
//        println("? %d %d".format(low + 1, high + 1))
        println(qSb)
        mode = br.readInt()
        if (mode == -1) {
            exitProcess(numQueries)
        }
        freq = br.readInt()
    }

    val n = br.readInt()
    val ans = IntArray(n)
    val queue: Queue<Pair<Int, Int>> = ArrayDeque(n shr 1)
    queue += Pair(0, n - 1)

    while (queue.isNotEmpty()) {
        val (l, r) = queue.poll()
        query(l, r)
        if (freq == r - l + 1) {
            for (x in l..r) {
                ans[x] = mode
            }
        } else if (freq == 1) {
            ans[l] = mode
            for (x in (l + 1)..r) {
                query(x, x)
                ans[x] = mode
            }
        } else if (freq > (r - l) shr 1) {
            val mid = (l + r) shr 1
            val groupMode = mode
            val groupFreq = freq
            query(l, mid)
            val lowMode = mode
            val lowFreq = freq
            var doLow = true
            val (low, high) = if (lowMode == groupMode) {
                Pair(mid + 1 - lowFreq, mid + groupFreq - lowFreq)
//            } else if (lowFreq == 1) {
//                doLow = false
//                ans[l] = lowMode
//                for (x in (l + 1)..mid) {
//                    query(x, x)
//                    ans[x] = mode
//                }
//                if (mode == groupMode) {
//                    Pair(mid, mid + groupFreq - 1)
//                } else {
//                    Pair(mid + 1, mid + groupFreq)
//                }
            } else {
                query(mid + 1, r)
                val highFreq = freq
                Pair(mid + 1 - (groupFreq - highFreq), mid + highFreq)
            }

            for (x in low..high) {
                ans[x] = groupMode
            }
            if (doLow && low > l) {
                queue += Pair(l, low - 1)
            }
            if (high < r) {
                queue += Pair(high + 1, r)
            }
        } else {
            for (newL in l..r step freq) {
                queue += Pair(newL, min(newL + freq - 1, r))
            }
        }
    }

    val sb = StringBuilder("! ")
    for (x in 0 until n) {
        sb.append(ans[x]).append(' ')
    }
    println(sb)
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