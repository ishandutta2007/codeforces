import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readLine()
        val next = arrayOf(charArrayOf('0', '5', '0', '5'), charArrayOf('0', '2', '5', '7'))
        val idxs = IntArray(4)
        var done = false
        for (x in n.indices) {
            if (done) break
            for (idx in 0 until 4) {
                if (n[n.lastIndex - x] == next[idxs[idx]][idx]) {
                    idxs[idx]++
                    if (idxs[idx] == 2) {
                        sb.appendLine(x - 1)
                        done = true
                        break
                    }
                }
            }
        }
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