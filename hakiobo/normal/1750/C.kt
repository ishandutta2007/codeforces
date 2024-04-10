import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val a = IntArray(n) { br.read() - '0'.toInt() }
        if (br.read() == '\r'.toInt()) br.read()
        val b = IntArray(n) { br.read() - '0'.toInt() }
        if (br.read() == '\r'.toInt()) br.read()
        var matches = 0
        var aOnes = 0
        for (i in 0 until n) {
            if (a[i] == b[i]) matches++
            if (a[i] == 1) aOnes++
        }
        if (matches in 1 until n) {
            bw.appendLine("NO")
        } else {
            bw.appendLine("YES")
            var moves = aOnes
            if (moves and 1 == 0 && matches == 0) moves += 3
            if (moves and 1 == 1 && matches != 0) moves += 3
            bw.appendLine("$moves")
            var movesMade = 0
            for (i in 0 until n) {
                if (a[i] == 1) {
                    bw.appendLine("${i + 1} ${i + 1}")
                    movesMade++
                }
            }
            if (movesMade < moves) {
                bw.appendLine("1 1")
                bw.appendLine("2 2")
                bw.appendLine("1 2")
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