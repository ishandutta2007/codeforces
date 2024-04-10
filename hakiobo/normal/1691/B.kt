import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val sizes = IntArray(n) { br.readInt() }
        val ans = IntArray(n)
        var start = 0
        var possible = true

        for (i in 1 until n) {
            if (sizes[i] == sizes[i - 1]) {
                ans[i - 1] = i + 1
            } else if (start == i - 1) {
                possible = false
            } else {
                ans[i - 1] = start + 1
                start = i
            }
        }
        if (start != n - 1) {
            ans[n - 1] = start + 1
        } else {
            possible = false
        }
        if (possible) {
            bw.appendLine(ans.joinToString(" "))
        } else {
            bw.appendLine("-1")
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