import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val pA = IntArray(n) { br.readInt() }.sortedArrayDescending()
        val pB = IntArray(n) { br.readInt() }.sortedArrayDescending()
        var scoreA = 0
        var scoreB = 0
        var rounds = n
        var numCount = n - (n shr 2)
        var idxA = numCount - 1
        for (x in 0 until numCount) {
            scoreA += pA[x]
            scoreB += pB[x]
        }
        while (scoreA < scoreB) {
            rounds++
            val newCount = rounds - (rounds shr 2)
            if (newCount > numCount) {
                scoreA += 100
                scoreB += if (numCount < n) pB[numCount] else 0
            } else {
                scoreA += 100 - pA[idxA--]
            }
            numCount = newCount
        }
        sb.appendLine(rounds - n)
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