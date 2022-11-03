import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val n = br.readInt()
    val k = br.readInt()
    val locationsByColor = Array(n) { IntArray(k) }
    val idxs = IntArray(n)
    val colors = IntArray(n * k) { idx ->
        val color = br.readInt() - 1
        locationsByColor[color][idxs[color]++] = idx
        color
    }
    val prev = IntArray(n * k)
    val latest = IntArray(n) { -1 }
    for (x in colors.indices) {
        val color = colors[x]
        prev[x] = latest[color]
        latest[color] = x
    }
    val used = BooleanArray(n)
    val starts = IntArray(n)
    val ends = IntArray(n)
    var numUsed = 0
    while (numUsed < n) {
        var cantinclude = -1
        for (x in 0 until (n * k)) {
            if (prev[x] > cantinclude && !used[colors[x]]) {
                val color = colors[x]
                cantinclude = x
                used[color] = true
                numUsed++
                starts[color] = prev[x]
                ends[color] = x
            }
        }
    }

    for (x in 0 until n) {
        sb.appendLine("${starts[x] + 1} ${ends[x] + 1}")
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