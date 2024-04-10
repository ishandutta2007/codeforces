import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val m = br.readInt()
        val k = br.readInt()
        val cts = Array(2) { IntArray(26) }
        for (c in br.readLine()) {
            cts[0][c - 'a']++
        }
        for (c in br.readLine()) {
            cts[1][c - 'a']++
        }
        var i = 0
        var j = 0
        var last = 0
        var stk = 0
        while (i < 26 && cts[0][i] == 0) i++
        while (j < 26 && cts[1][j] == 0) j++
        while (i < 26 && j < 26) {
            val placeA = if (i < j) {
                last == 1 || stk < k
            } else {
                last == 1 && stk == k
            }
            if (placeA) {
                cts[0][i]--
                bw.append('a' + i)
                if (last == 1) {
                    last = 0
                    stk = 0
                }
            } else {
                cts[1][j]--
                bw.append('a' + j)
                if (last == 0) {
                    last = 1
                    stk = 0
                }
            }
            stk++

            while (i < 26 && cts[0][i] == 0) i++
            while (j < 26 && cts[1][j] == 0) j++
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