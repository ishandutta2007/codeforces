import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val q = br.readInt()
    repeat(q) {
        val s = br.readLine()
        val t = br.readLine()
        var sIdx = s.lastIndex
        var tIdx = t.lastIndex
        while (sIdx >= 0 && tIdx >= 0) {
            if (s[sIdx] == t[tIdx]) {
                tIdx--
                sIdx--
            } else {
                sIdx -= 2
            }
        }
        if(tIdx >= 0) sb.appendLine("NO") else sb.appendLine("YES")
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