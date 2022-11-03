import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val m = br.readInt()
        val state = br.readLine().toCharArray()
        var iterations = 0
        var changed = true
        while (iterations < m && changed) {
            changed = false
            val prev = state.toList()
            for (x in 1 until n - 1) {
                if (prev[x - 1] != prev[x + 1]) {
                    if (prev[x] == '0') {
                        state[x] = '1'
                        changed = true
                    }
                }
            }
            if (prev[0] == '0' && prev[1] == '1') {
                changed = true
                state[0] = '1'
            }
            if (prev[n - 1] == '0' && prev[n - 2] == '1') {
                changed = true
                state[n - 1] = '1'
            }
            iterations++
        }
        sb.appendLine(state.joinToString(""))
    }
    print(sb)
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