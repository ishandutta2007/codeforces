import java.io.BufferedReader
import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val words = Array(n) {
            br.readLine()
        }
        val scoreByLetter = Array(5) {
            IntArray(n)
        }
        for (idx in 0 until n) {
            val letterCount = IntArray(5)
            val len = words[idx].length
            for (c in words[idx]) {
                letterCount[c - 'a']++
            }
            for (letter in 0 until 5) {
                scoreByLetter[letter][idx] = (letterCount[letter] shl 1) - len
            }
        }
        val sortedByLetter = Array(5) { letter ->
            IntArray(n) { it }.sortedByDescending { idx -> scoreByLetter[letter][idx] }
        }
        var bestToTake = 0
        for (letter in 0 until 5) {
            var score = 0
            var next = 0
            while (next < n && score + scoreByLetter[letter][sortedByLetter[letter][next]] > 0) {
                score += scoreByLetter[letter][sortedByLetter[letter][next]]
                next++
            }
            bestToTake = max(next, bestToTake)
        }
        sb.appendLine(bestToTake)
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