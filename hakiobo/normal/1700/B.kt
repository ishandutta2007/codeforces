import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val num = br.readLine()

        val ans = CharArray(n)
        var carry = 0
        if (num[0] == '9') {
            for (i in n - 1 downTo 0) {
                val part = num[i] - '0' + carry
                if (part > 1) {
                    ans[i] = '0' + (11 - part)
                    carry = 1
                } else {
                    ans[i] = '0' + (1 - part)
                    carry = 0
                }
            }
            for (c in ans) {
                bw.append(c)
            }
        } else {
            for (c in num) {
                bw.append('0' + (9 - (c - '0')))
            }
        }


        bw.newLine()
    }
    bw.flush()
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