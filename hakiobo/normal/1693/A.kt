import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val leftJumpsFrom = LongArray(n)
        val rightJumpsFrom = LongArray(n)
        rightJumpsFrom[0] = br.readInt().toLong()

        for (i in 1 until n) {
           val rMinusL = br.readInt().toLong()
            leftJumpsFrom[i] = rightJumpsFrom[i - 1]
            rightJumpsFrom[i] = rMinusL + leftJumpsFrom[i]
        }
        var foundZero = false
        var good = true
        for(i in 0 until n) {
            if(rightJumpsFrom[i] < 0 || leftJumpsFrom[i] < 0) {
                good = false
            }
            if(foundZero && rightJumpsFrom[i] != 0L) good = false
            if(rightJumpsFrom[i] == 0L) foundZero = true
        }
        if (good && foundZero) {
            bw.appendLine("YES")
        } else {
            bw.appendLine("NO")
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