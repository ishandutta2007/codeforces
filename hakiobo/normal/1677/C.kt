import java.io.BufferedReader
import kotlin.math.absoluteValue

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()


    repeat(t) {
        val n = br.readInt()
        val ca = IntArray(n) { br.readInt() - 1 }
        val cb = IntArray(n) { br.readInt() - 1 }
        val revA = IntArray(n)
        val revB = IntArray(n)
        for (i in 0 until n) {
            revA[ca[i]] = i
            revB[cb[i]] = i
        }
        val used = BooleanArray(n)
        var evenLength = 0L
        for (start in 0 until n) {
            var l = 0
            var cur = start
            while (!used[cur]) {
                used[cur] = true
                l++
                cur = cb[revA[cur]]
            }
            evenLength += if (l and 1 == 0) {
                l shr 1
            } else {
                (l - 1) shr 1
            }
        }
        var aboveSum = 0L
        val belowSum = (evenLength * (evenLength + 1)) shr 1
        for (i in n downTo n - evenLength + 1) {
            aboveSum += i
        }
        bw.appendLine(((aboveSum - belowSum) shl 1).toString())
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