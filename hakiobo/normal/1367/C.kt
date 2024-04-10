import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readInt()
    repeat(numCases) {
        val n = br.readInt()
        val k = br.readInt()
        val w = br.readLine().toCharArray().map { it == '1' }.toBooleanArray()
        var ctr = -1
        for (idx in w.indices) {
            val c = w[idx]
            if (c) {
                ctr = k
            }
            if (ctr >= 0) {
                w[idx] = true
            }
            ctr--
        }
        ctr = -1
        for (idx in w.lastIndex downTo 0) {
            val c = w[idx]
            if (c) {
                ctr = k
            }
            if (ctr >= 0) {
                w[idx] = true
            }
            ctr--
        }

        ctr = -1
        var numToAdd = 0
        for (idx in w.indices) {
            val c = w[idx]

            if (ctr >= 0) {
                w[idx] = true
            } else if (!c) {
                numToAdd++
                ctr = k
            }
            ctr--
        }
        sb.append(numToAdd).append('\n')
    }
    print(sb)
}

private const val SPACE_INT = ' '.toInt()
private const val ZERO_INT = '0'.toInt()
private const val NL_INT = '\n'.toInt()

@Suppress("DuplicatedCode")
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