import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val k = br.readInt()
    val elements = IntArray(n) { br.readInt() }.sortedArray()
    var sum = 0
    val sb = StringBuilder()
    var idx = 0
    for (z in 0 until k) {
        while (idx < n && elements[idx] == sum) {
            idx++
        }
        if (idx == n) {
            sb.appendLine(0)
        } else {
            sb.appendLine(elements[idx] - sum)
            sum = elements[idx++]
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