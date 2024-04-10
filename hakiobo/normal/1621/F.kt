import java.io.BufferedReader
import kotlin.math.max


private fun solve(a: Long, b: Long, c: Long, s: String): Long {
    val n = s.length
    val internalZSizes = mutableListOf<Int>()
    var internalZIdx = 0
    var internalZSize1 = 0
    var externalZSize1 = 0
    var oMoves = 0
    var externalZMoves = 0
    var begin = 0
    var end = n - 1
    var oddStart = true
    while (begin < n && s[begin] == '0') {
        begin++
    }
    while (end >= 0 && s[end] == '0') {
        end--
    }

    if (end < begin) return if (n == 1) 0 else a
    externalZMoves = max(0, begin - 1) + max(0, n - end - 2)
    if (begin > 0) externalZSize1++
    if (end < n - 1) externalZSize1++
    var curChar = ' '
    var curSize = 0
    for (x in begin..end) {
        if (s[x] == curChar) {
            curSize++
        } else {
            when (curChar) {
                '0' -> {
                    internalZSizes += curSize
                }
                '1' -> {
                    oMoves += max(0, curSize - 1)
                }
            }
            curChar = s[x]
            curSize = 1
        }
    }
    when (curChar) {
        '0' -> {
            internalZSizes += curSize
        }
        '1' -> {
            oMoves += max(0, curSize - 1)
        }
    }
    internalZSizes.sort()

    var profit = 0L
    while (true) {
        while (internalZIdx < internalZSizes.size && internalZSizes[internalZIdx] == 1) {
            internalZIdx++
            internalZSize1++
        }

        if (oMoves > 0) {
            if (internalZIdx < internalZSizes.size) {
                oMoves--
                internalZSizes[internalZIdx]--
                profit += a + b
            } else if (externalZMoves > 0) {
                oMoves--
                externalZMoves--
                profit += a + b
            } else if (oddStart){
                oMoves--
                oddStart = false
                profit += b
            } else if(c > b){
                return profit
            } else if(internalZSize1 > 0){
                internalZSize1--
                profit += b - c
            } else if(externalZSize1 > 0){
                oMoves--
                externalZSize1--
                profit += b - c
            } else {
                return profit
            }
        } else if (c > b) {
            return if (internalZIdx < internalZSizes.size || externalZMoves > 0) {
                profit + a
            } else {
                profit
            }
        } else if (internalZSize1 > 0) {
            internalZSize1--
            profit += b - c
        } else if (internalZIdx < internalZSizes.size || externalZMoves > 0) {
            return profit + a
        } else {
            return profit
        }
    }
}

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val a = br.readInt().toLong()
        val b = br.readInt().toLong()
        val c = br.readInt().toLong()
        val s = br.readLine()
        sb.appendLine(solve(a, b, c, s))

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