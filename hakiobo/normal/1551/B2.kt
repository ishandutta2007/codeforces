import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val k = br.readInt()
        val counts = Array(n + 1) { mutableListOf<Int>() }
        val indexes = IntArray(n + 1)
        val array = IntArray(n) { br.readInt() }
        var cantPaint = 0
        for (x in array.indices) {
            val num = array[x]
            if (counts[num].size < k) {
                counts[num].add(x)
            } else {
                cantPaint++
            }
        }
        val numTimes = ((n - cantPaint) / k) * k
        val ans = IntArray(n)
        var idx = 0
        for (numPainted in 0 until numTimes) {
            while (counts[idx].size == indexes[idx]) {
                idx++
            }
            ans[counts[idx][indexes[idx]]] = (numPainted % k) + 1
            indexes[idx]++
        }
        sb.appendLine(ans.joinToString(" "))
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