import java.io.BufferedReader
import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val n = br.readInt()
    val scores = List(n) { br.readInt() }.sorted().toIntArray()
    val otherScores = List(n + 1) { br.readInt() }.sorted().toIntArray()
    val prefixScores = IntArray(n)
    prefixScores[0] = otherScores.first() - scores.first()
    for (x in 1 until n) {
        prefixScores[x] = max(prefixScores[x - 1], otherScores[x] - scores[x])
    }
    val suffixScores = IntArray(n)
    suffixScores[n - 1] = otherScores[n] - scores[n - 1]
    for (x in n - 2 downTo 0) {
        suffixScores[x] = max(suffixScores[x + 1], otherScores[x + 1] - scores[x])
    }
    val m = br.readInt()
    repeat(m) {
        val num = br.readInt()
        var low = 0
        var high = n
        var mid = (low + high) shr 1
        while (low < high) {
            if (scores[mid] < num) {
                low = mid + 1
            } else {
                high = mid
            }
            mid = (low + high) shr 1
        }
        var score = otherScores[mid] - num
        if (mid > 0) {
            score = max(score, prefixScores[mid - 1])
        }
        if (mid < n) {
            score = max(score, suffixScores[mid])
        }
        sb.append(score).append(" ")
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