import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val s = br.readLine()
        var zGroups = 0
        var oGroups = 0
        var prev = 'a'
        for (c in s) {
            when (c) {
                prev -> {
                    //nothing
                }
                '0' -> {
                    prev = '0'
                    zGroups++
                }
                '1' -> {
                    prev = '1'
                    oGroups++
                }
            }
        }
        when (zGroups) {
            0 -> sb.appendLine(0)
            1 -> sb.appendLine(1)
            else -> sb.appendLine(2)
        }
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