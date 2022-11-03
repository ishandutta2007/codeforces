import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val s = br.readLine()
        val mid = findBestPrefix(s)
        sb.append(s.substring(0, mid + 1)).appendLine(s.substring(0, mid + 1).reversed())
    }
    println(sb)
}

private fun findBestPrefix(s: String): Int {
    val n = s.length
    var mid = 0
    if (n >= 2 && s[0] == s[1]) {
        return 0
    }
    while (mid + 1 < n) {
        if (s[mid] < s[mid + 1]) {
            return mid
        } else {
            mid++
        }
    }
    return n - 1
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