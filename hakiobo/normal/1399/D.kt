import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val s = br.readLine()
        val color = IntArray(n)
        var curOneGroups = 0
        var curZeroGroups = 0
        for (idx in s.indices) {
            val c = s[idx]
            if (c == '0') {
                if (curOneGroups == 0) {
                    color[idx] = curOneGroups + curZeroGroups + 1
                    curZeroGroups++
                } else {
                    color[idx] = curZeroGroups + 1
                    curOneGroups--
                    curZeroGroups++
                }
            } else {
                if (curZeroGroups == 0) {
                    color[idx] = curOneGroups + curZeroGroups + 1
                    curOneGroups++
                } else {
                    color[idx] = curZeroGroups
                    curZeroGroups--
                    curOneGroups++
                }
            }
        }
        sb.append(curOneGroups + curZeroGroups).append('\n').append(color.joinToString(" ")).append('\n')
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