import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val m = br.readInt()
        val s = br.readLine()
        val goodRowCt = IntArray(n * m)
        val goodColCt = IntArray(n * m)
        val isGoodCol = BooleanArray(m)
        var lastGood = -(n * m + 1)
        var numGoodCols = 0
        for (i in 0 until n * m) {
            val col = i % m
            if (s[i] == '1') {
                lastGood = i
                if (!isGoodCol[col]) {
                    isGoodCol[col] = true
                    numGoodCols++
                }
            }
            goodColCt[i] = numGoodCols
            if (i - lastGood < m) {
                goodRowCt[i]++
            }
            if (i - m >= 0) {
                goodRowCt[i] += goodRowCt[i - m]
            }
        }
        for (i in 0 until n * m) {
            bw.append("${goodColCt[i] + goodRowCt[i]} ")
        }
        bw.newLine()
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