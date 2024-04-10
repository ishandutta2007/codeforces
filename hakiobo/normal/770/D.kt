import java.io.BufferedReader
import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val n = br.readInt()
    val seq = br.readLine()
    val depth = IntArray(n)
    depth[0] = 1
    var high = 1
    var curBal = 1
    for (i in 0 until n - 1) {
        if (seq[i + 1] == '[') {
            depth[i + 1] = ++curBal
            high = max(high, depth[i + 1])
        } else {
            depth[i + 1] = curBal--
        }
    }
    var directlyNextTo = 0
    for (i in 1 until n) {
        if (seq[i - 1] == '[' && seq[i] == ']') {
            directlyNextTo++
        }
    }
    val ans = Array(2 * high + 1) { CharArray(n + directlyNextTo * 3) { ' ' } }
    val colStarts = IntArray(n)
    var cur = 0
    colStarts[0] = 0
    for (i in 1 until n) {
        cur++
        if (seq[i - 1] == '[' && seq[i] == ']') cur += 3
        colStarts[i] = cur
    }

    for (i in 0 until n) {
        if (seq[i] == '[') {
            val height = high - depth[i] + 1
            for (row in high - height + 1 until high + height) {
                ans[row][colStarts[i]] = '|'
            }
            ans[high + height][colStarts[i]] = '+'
            ans[high - height][colStarts[i]] = '+'
            ans[high + height][colStarts[i] + 1] = '-'
            ans[high - height][colStarts[i] + 1] = '-'
        } else {
            val height = high - depth[i] + 1
            for (row in high - height + 1 until high + height) {
                ans[row][colStarts[i]] = '|'
            }
            ans[high + height][colStarts[i]] = '+'
            ans[high - height][colStarts[i]] = '+'
            ans[high + height][colStarts[i] - 1] = '-'
            ans[high - height][colStarts[i] - 1] = '-'
        }
    }
    for (row in ans) {
        bw.appendLine(row.joinToString(""))
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