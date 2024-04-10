import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val n = br.readInt()
    val m = br.readInt()
    val d = br.readInt()
    val a = IntArray(n) { br.readInt() }
    val sorted = (0 until n).sortedBy { a[it] }
    val ans = IntArray(n)
    var j = 0
    var high = 0
    for(i in 0 until n) {
        if(ans[sorted[i]] == 0) ans[sorted[i]] = ++high
        while (j < n && a[sorted[j]] - a[sorted[i]] <= d) {
            j++
        }
        if(j < n) ans[sorted[j++]] = ans[sorted[i]]
    }
    bw.appendLine(high.toString())
    bw.appendLine(ans.joinToString(" "))
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