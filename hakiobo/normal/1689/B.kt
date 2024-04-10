import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val p = IntArray(n) { br.readInt() - 1 }

        if (n == 1) {
            bw.appendLine("-1")
        } else {
            val ans = IntArray(n)
            val used = BooleanArray(n)
            for (i in 0 until n - 1) {
                for (j in 0 until n) {
                    if (!used[j] && p[i] != j) {
                        used[j] = true
                        ans[i] = j + 1
                        break
                    }
                }
            }
            for (i in 0 until n) {
                if (!used[i]) {
                    if (i == p[n - 1]) {
                        ans[n - 1] = ans[n - 2]
                        ans[n - 2] = i + 1
                    } else {
                        ans[n - 1] = i + 1
                    }
                    break
                }
            }
            bw.appendLine(ans.joinToString(" "))
        }
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