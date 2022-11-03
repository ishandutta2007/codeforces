import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        if (n <= 3) {
            sb.append(-1).append('\n')
        } else {
            var num = 2
            repeat(n) {
                sb.append(num).append(' ')
                if (num and 1 == 0) {
                    num += 2
                    if (num > n) {
                        num -= 5
                    }
                } else if (num == n - 1) {
                    num -= 4
                } else if (num == n - 3) {
                    num += 2
                } else if (num == n - 4) {
                    num += 4
                } else if (num == n - 2) {
                    num -= 4
                } else {
                    num -= 2
                }
            }
            sb.append('\n')
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