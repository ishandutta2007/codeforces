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
        val s = br.readLine()
        var beginningStreak = 0
        val streaks = mutableListOf<Int>()
        var first = true
        var cur = 0
        var score = 0
        var wonPrev = false
        for (c in s) {
            if (c == 'W') {
                score += if (wonPrev) 2 else 1
                if (first) {
                    beginningStreak = cur
                    first = false
                } else if (cur != 0) {
                    streaks += cur
                }
                cur = 0
                wonPrev = true
            } else {
                cur++
                wonPrev = false
            }
        }
        beginningStreak += cur
        if (!first) {
            val sorted = streaks.sorted()
            var streakID = 0
            var changes = 0
            while (changes < k && streakID < sorted.size) {
                val curStreak = sorted[streakID]
                if (curStreak + changes <= k) {
                    changes += curStreak
                    score += curStreak * 2 + 1
                } else {
                    score += 2 * (k - changes)
                    changes = k
                }
                streakID++
            }
            if (changes != k) {
                score += 2 * min( k - changes, beginningStreak)
            }
        } else {
            score = max(2 * k - 1, 0)
        }
        sb.append(score).append("\n")

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