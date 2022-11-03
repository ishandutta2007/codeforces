import java.io.BufferedReader
import kotlin.math.absoluteValue

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val a = br.readInt()
        val b = br.readInt()
        val digits = br.readLine().reversed().map { it - '0' }.toIntArray()
        val aTen = IntArray(n)
        val bTen = IntArray(n)
        aTen[0] = 1
        bTen[0] = 1
        for (x in 1 until n) {
            aTen[x] = (10 * aTen[x - 1]) % a
            bTen[x] = (10 * bTen[x - 1]) % b
        }
        val dp = Array(n + 1) { Array(n + 1 - it) { Array(a) { BooleanArray(b) } } }
        val prev = Array(n + 1) { Array(n + 1 - it) { Array(a) { BooleanArray(b) } } }
        dp[0][0][0][0] = true
        for (totUsed in 0 until n) {
            for (aUsed in 0..totUsed) {
                val bUsed = totUsed - aUsed
                for (aMod in 0 until a) {
                    for (bMod in 0 until b) {
                        if (!dp[aUsed][bUsed][aMod][bMod]) continue
                        val newA = (aMod + digits[totUsed] * aTen[aUsed]) % a
                        val newB = (bMod + digits[totUsed] * bTen[bUsed]) % b
                        dp[aUsed + 1][bUsed][newA][bMod] = true
                        prev[aUsed + 1][bUsed][newA][bMod] = true
                        dp[aUsed][bUsed + 1][aMod][newB] = true
                        prev[aUsed][bUsed + 1][aMod][newB] = false
                    }
                }
            }
        }
        var bestA = 0
        for (aUsed in 1 until n) {
            val bUsed = n - aUsed
            if (dp[aUsed][bUsed][0][0]) {
                if ((aUsed - bUsed).absoluteValue < (bestA * 2 - n).absoluteValue) {
                    bestA = aUsed
                }
            }
        }
        if (bestA == 0) {
            sb.appendLine(-1)
        } else {
            var aU = bestA
            var bU = n - bestA
            var aM = 0
            var bM = 0
            repeat(n) {
                if (prev[aU][bU][aM][bM]) {
                    sb.append("R")
                    aU--
                    aM -= digits[aU + bU] * aTen[aU]
                    aM %= a
                    aM += a
                    aM %= a
                } else {
                    sb.append("B")
                    bU--
                    bM -= digits[aU + bU] * bTen[bU]
                    bM %= b
                    bM += b
                    bM %= b
                }
            }
            sb.appendLine()
        }
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