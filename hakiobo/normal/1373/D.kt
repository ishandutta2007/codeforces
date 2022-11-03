import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val nums = LongArray(n) { br.readInt().toLong() }
        val partial = nums.filterIndexed { index, _ -> index and 1 == 0 }.sum()
        val num2 = LongArray(n shr 1) { idx ->
            nums[(idx shl 1) + 1] - nums[idx shl 1]
        }
        val num3 = LongArray((n - 1) shr 1) { idx ->
            nums[(idx shl 1) + 1] - nums[(idx shl 1) + 2]
        }
        var best = 0L
        var cur = 0L
        for (i in num2.indices) {
            cur = num2[i].coerceAtLeast(cur + num2[i])
            best = best.coerceAtLeast(cur)
        }
        cur = 0L
        for (i in num3.indices) {
            cur = num3[i].coerceAtLeast(cur + num3[i])
            best = best.coerceAtLeast(cur)
        }
        sb.append(best + partial).append('\n')
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