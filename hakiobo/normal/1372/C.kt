import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        var numInPlace = 0
        var prefix = 0
        var suffix = 0
        for (x in 1..n) {
            val num = br.readInt()
            if (num == x) {
                numInPlace++
                if (prefix + 1 == x) {
                    prefix++
                }
                suffix++
            } else {
                suffix = 0
            }
        }
        if (numInPlace == n) {
            sb.append("0\n")
        } else if (numInPlace == (prefix + suffix)) {
            sb.append("1\n")
        } else {
            sb.append("2\n")
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