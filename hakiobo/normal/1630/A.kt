import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val k = br.readInt()
        val mask = n - 1
        val partner = IntArray(n) { num -> mask xor num }
        var valid = true
        if (k != 0) {
            if (k != mask) {
                partner[k] = mask
                partner[mask] = k
                partner[0] = mask xor k
                partner[mask xor k] = 0
            } else {
                if (n == 4) {
                    valid = false
                } else {
                    partner[0] = 2
                    partner[2] = 0
                    partner[1] = mask - 2
                    partner[mask - 2] = 1
                    partner[mask] = mask - 1
                    partner[mask - 1] = mask
                }
            }
        }
        if (valid) {
            for (x in 0 until n) {
                if (x < partner[x]) {
                    sb.appendLine("$x ${partner[x]}")
                }
            }
        } else {
            sb.appendLine(-1)
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