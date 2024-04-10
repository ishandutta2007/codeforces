import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val a = br.readInt().toLong()
        val b = br.readInt().toLong()
        if (b == 1L) {
            sb.append("NO\n")
        } else if (b != 2L) {
            //a * (b - 1), a, a*b
            sb.append("YES\n").append("${a * b - a} $a ${a * b}\n")
        } else {
            //a * (4b - 1), a, 4*a*b
            sb.append("YES\n").append("${4 * a * b - a} $a ${4 * a * b}\n")
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