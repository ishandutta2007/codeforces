import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val q = br.readInt()
    repeat(q) {
        val n = br.readInt()
        val s = br.readLine()
        val t = br.readLine()
        var good = true
        val balance = IntArray(3)
        for (i in 0 until n) {
            balance[s[i] - 'a']++
            if (balance[0] != 0 && balance[2] != 0) good = false
            balance[t[i] - 'a']--
            if (balance[0] < 0) good = false
            if (balance[2] > 0) good = false
            if (balance[0] != 0 && balance[2] != 0) good = false
        }
        if (!balance.all { it == 0 }) good = false


        if (good) {
            bw.appendLine("YES")
        } else {
            bw.appendLine("NO")
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