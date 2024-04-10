import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val nHalf = br.readInt()
        val n = nHalf shl 1
        val p = IntArray(n) { br.readInt() - 1 }
        val reverse = IntArray(n)
        for (x in 0 until n) {
            reverse[p[x]] = x
        }
        val reachAbleSizes = BooleanArray(nHalf + 1)
        reachAbleSizes[0] = true
        var lastIdx = n
        for (x in (n - 1) downTo 0) {
            val nextIdx = reverse[x]
            if (nextIdx < lastIdx) {
                val dif = lastIdx - nextIdx
                for (y in (nHalf - dif) downTo 0) {
                    if (reachAbleSizes[y]) {
                        reachAbleSizes[y + dif] = true
                    }
                }
                lastIdx = nextIdx
            }
        }
        sb.append(if (reachAbleSizes.last()) "YES\n" else "NO\n")
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