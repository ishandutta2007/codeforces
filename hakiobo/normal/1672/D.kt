import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val a = IntArray(n) { br.readInt() - 1 }
        val b = IntArray(n) { br.readInt() - 1 }
        val needToMove = IntArray(n)
        var i = 0
        var j = 0
        while (i < n) {
            if (a[i] == b[j]) {
                i++
                j++
            } else if (j != 0 && b[j] == b[j - 1] && needToMove[b[j]] != 0) {
                needToMove[b[j++]]--
            } else {
                needToMove[a[i++]]++
            }
        }
        while (j < n && b[j] == b[j - 1] && needToMove[b[j]] != 0) {
            needToMove[b[j++]]--
        }
        if(j == n) {
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