import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val k = br.readInt()
        val likes = br.readLine().map { it == '1' }
        val next = IntArray(n) { idx -> (idx + 1) % n }
        val prev = IntArray(n) { idx -> (idx + n - 1) % n }
        var numLike = likes.count { it }
        var nextToEat = 0
        var numLeft = n
        while (numLike > 0) {
            if (likes[nextToEat]) {
                numLike--
            }
            numLeft--
            val nx = next[nextToEat]
            val pv = prev[nextToEat]
            next[pv] = nx
            prev[nx] = pv
            nextToEat = nx
            repeat(k - 1) {
                nextToEat = next[nextToEat]
            }
        }
        sb.appendLine(n - numLeft)
    }
    print(sb)
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