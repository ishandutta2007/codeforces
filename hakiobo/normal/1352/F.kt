import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val zz = br.readInt()
        val oz = br.readInt()
        val oo = br.readInt()
        var ptr = 1
        if (oz == 0) {
            if (oo != 0) {
                repeat(oo + 1) { sb.append(1) }
            } else {
                repeat(zz + 1) { sb.append(0) }
            }
        } else {
            repeat(zz + 1) { sb.append(0) }
            repeat(oo + 1) { sb.append(1) }
            repeat((oz - 1) shr 1) { sb.append("01") }
            if (oz and 1 == 0) sb.append(0)
        }
        sb.append('\n')
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