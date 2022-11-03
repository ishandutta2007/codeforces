import java.io.BufferedReader
import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readInt()
    repeat(numCases) {
        val n = br.readInt()
        val map = TreeMap<Int, MutableList<Int>>()
        repeat(n) { idx ->
            val num = br.readInt()
            if (num !in map) {
                map[num] = mutableListOf()
            }
            map[num]!!.add(idx)
        }
        for (values in map.values) {
            values.sort()
        }

        val itr = map.iterator()
        var prev = itr.next().value
        var streak = prev.size
        var maxStreak = streak
        while (itr.hasNext()) {
            val cur = itr.next().value
            if (prev.last() < cur.first()) {
                streak += cur.size
            } else {
                var prevIdx = 0
                for (idx in cur.indices) {
                    while (prevIdx < prev.size && prev[prevIdx] < cur[idx]) {
                        prevIdx++
                        maxStreak = maxStreak.coerceAtLeast(cur.size - idx + if (prevIdx == prev.size) streak else prevIdx)
                    }
                }
                streak = cur.size
                for (idx in prev.indices) {
                    if (prev[idx] < cur.first()) {
                        streak++
                    } else {
                        break
                    }
                }
            }
            prev = cur
            maxStreak = maxStreak.coerceAtLeast(streak)
        }
        sb.append(n - maxStreak).append('\n')
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