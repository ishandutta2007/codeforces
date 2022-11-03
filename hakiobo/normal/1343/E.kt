import java.io.BufferedReader
import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val m = br.readInt()
        val a = br.readInt() - 1
        val b = br.readInt() - 1
        val c = br.readInt() - 1
        val prices = LongArray(m + 1) { idx -> if (idx == 0) 0L else br.readLong() }.sortedArray()

        var cum = 0L
        val cons = Array(n) { mutableListOf<Int>() }
        repeat(m) { idx ->
            cum += prices[idx + 1]
            prices[idx + 1] = cum
            val u = br.readInt() - 1
            val v = br.readInt() - 1
            cons[u].add(v)
            cons[v].add(u)
        }
        val distFromA = IntArray(n) { -1 }
        val queue: Queue<Int> = ArrayDeque()
        queue += a
        distFromA[a] = 0
        while (queue.isNotEmpty()) {
            val cur = queue.poll()
            val curDist = distFromA[cur]
            for (adj in cons[cur]) {
                if (distFromA[adj] == -1) {
                    distFromA[adj] = curDist + 1
                    queue += adj
                }
            }
        }

        val distFromC = IntArray(n) { -1 }
        queue += c
        distFromC[c] = 0
        while (queue.isNotEmpty()) {
            val cur = queue.poll()
            val curDist = distFromC[cur]
            for (adj in cons[cur]) {
                if (distFromC[adj] == -1) {
                    distFromC[adj] = curDist + 1
                    queue += adj
                }
            }
        }
        var price = Long.MAX_VALUE
        val distFromB = IntArray(n) { -1 }
        distFromB[b] = 0
        queue += b
        while (queue.isNotEmpty()) {
            val cur = queue.poll()
            val curA = distFromA[cur]
            val curB = distFromB[cur]
            val curC = distFromC[cur]
            if (curA + curB + curC <= m) {
                price = price.coerceAtMost(prices[curB] + prices[curA + curB + curC])
            }
            for (adj in cons[cur]) {
                if (distFromB[adj] == -1) {
                    distFromB[adj] = curB + 1
                    queue += adj
                }
            }
        }

        sb.append(price).append('\n')
    }
    print(sb)
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

@Suppress("DuplicatedCode")
private fun BufferedReader.readLong(): Long {
    var ret = read().toLong()
    while (ret <= SPACE_INT) {
        ret = read().toLong()
    }
    val neg = ret == '-'.toLong()
    if (neg) {
        ret = read().toLong()
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