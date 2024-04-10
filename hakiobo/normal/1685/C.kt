import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val bracks = BooleanArray(n shl 1) { br.read().toChar() == '(' }
        var curPref = 0
        var good = true
        for (c in bracks) {
            if (c) {
                curPref++
            } else if (--curPref < 0) {
                good = false
                break
            }
        }
        if (good) {
            bw.appendLine("0")
        } else {
            var bestT = -1
            var bestTI = -1
            var bestL = -1
            var bestLI = 0
            var bestR = -1
            var bestRI = 2 * n - 1

            var cur = 0
            for (i in 0 until 2 * n) {
                if (bracks[i]) {
                    cur++
                    if (cur > bestT) {
                        bestT = cur
                        bestTI = i
                    }
                } else {
                    cur--
                }
            }
            cur = 0
            for (i in 0 until 2 * n) {
                if (bracks[i]) {
                    cur++
                    if (cur > bestL) {
                        bestL = cur
                        bestLI = i + 1
                    }
                } else if (--cur == -1) {
                    break
                }
            }
            cur = 0
            for (i in 2 * n - 1 downTo 0) {
                if (!bracks[i]) {
                    cur++
                    if (cur > bestR) {
                        bestR = cur
                        bestRI = i - 1
                    }
                } else if (--cur == -1) {
                    break
                }
            }
            bracks.reverse(bestLI, bestRI + 1)
            cur = 0
            good = true
            for (brack in bracks) {
                if (brack) {
                    cur++
                } else if (--cur < 0) {
                    good = false
                    break
                }
            }
            if (good) {
                bw.appendLine("1")
                bw.appendLine("${bestLI + 1} ${bestRI + 1}")
            } else {
                bw.appendLine("2")
                bw.appendLine("1 ${bestTI + 1}")
                bw.appendLine("${bestTI + 2} ${2 * n}")
            }
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