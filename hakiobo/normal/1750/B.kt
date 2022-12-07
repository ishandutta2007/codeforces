import java.io.BufferedReader
import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val num = br.readLine()
        var curStreak = 0L
        var maxZ = 0L
        var maxO = 0L
        var totZ = 0L
        var totO = 0L
        var prev = -1

        for(digit in num) {
            val d = digit - '0'
            if(prev == d) {
                curStreak++
            } else {
                curStreak = 1
            }
            if(d == 0) {
                totZ++
                maxZ = max(maxZ, curStreak)
            } else {
                totO++
                maxO = max(maxO, curStreak)
            }
            prev = d
        }
        bw.appendLine("${max(totO * totZ, max(maxO * maxO, maxZ * maxZ))}")
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