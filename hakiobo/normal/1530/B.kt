import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val r = br.readInt()
        val c = br.readInt()
        repeat(c) { col ->
            if (col and 1 == 0) {
                sb.append('1')
            } else {
                sb.append('0')
            }
        }
        sb.appendLine()
        for (row in 1 until r - 1) {
            if (row and 1 == 1) {
                sb.appendLine("0".repeat(c))
            } else {
                sb.append("1").append("0".repeat(c - 2)).appendLine("1")
            }
        }
        if (r and 1 == 1) {
            sb.append("1")
        } else {
            sb.append("0")
        }
        for (col in 1 until c - 2) {
            if (col and 1 == 0) {
                sb.append("1")
            } else {
                sb.append("0")
            }
        }
        for (col in c - 2 until c) {
            if (r and 1 == 1 && col and 1 == 0) {
                sb.append("1")
            } else {
                sb.append("0")
            }
        }
        sb.appendLine().appendLine()
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