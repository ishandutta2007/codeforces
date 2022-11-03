import java.io.BufferedReader
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        var k = br.readInt()
        val s = br.readLine()
        var firstO = n
        var lastO = -1
        var oCt = 0
        for (i in 0 until n) {
            if (s[i] == '1') {
                oCt++
                lastO = i
                firstO = min(firstO, i)
            }
        }
        if (oCt == 0) {
            bw.appendLine("0")
        } else if (oCt == 1) {
            if (n - 1 - lastO <= k) {
                bw.appendLine("1")
            } else if (firstO <= k) {
                bw.appendLine("10")
            } else {
                bw.appendLine("11")
            }
        } else {
            var baseAns = oCt * 11
            if (n - 1 - lastO <= k) {
                baseAns -= 10
                k -= n - 1 - lastO
            }
            if (firstO <= k) {
                baseAns--
            }
            bw.appendLine(baseAns.toString())
        }


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