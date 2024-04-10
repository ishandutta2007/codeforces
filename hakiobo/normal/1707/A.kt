import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val q = br.readInt()
        val difs = IntArray(n) { br.readInt() }
        var cur = 0
        val ans = CharArray(n)
        for (i in n - 1 downTo 0) {
            if (difs[i] <= cur) {
                ans[i] = '1'
            } else if (cur < q) {
                cur++
                ans[i] = '1'
            } else {
                ans[i] = '0'
            }
        }
        for (i in 0 until n) {
            bw.append(ans[i])
        }
        bw.appendLine()
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