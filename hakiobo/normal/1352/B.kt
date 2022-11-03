import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val k = br.readInt()
        if (n and 1 == k and 1) {
            if (k > n) {
                sb.append("NO\n")
            } else {
                sb.append("YES\n")
                repeat(k - 1) {
                    sb.append("1 ")
                }
                sb.append(n - k + 1).append('\n')
            }
        } else if (n and 1 == 0) {
            if (k shl 1 > n) {
                sb.append("NO\n")
            } else {
                sb.append("YES\n")
                repeat(k - 1) {
                    sb.append("2 ")
                }
                sb.append(n - 2 * k + 2).append('\n')
            }
        } else {
            sb.append("NO\n")
        }
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