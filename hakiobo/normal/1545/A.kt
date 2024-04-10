import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val nums = IntArray(n) { br.readInt() }
        val evens = IntArray((n + 1) shr 1) { idx -> nums[idx shl 1] }.sortedArray()
        val odds = IntArray(n shr 1) { idx -> nums[(idx shl 1) + 1] }.sortedArray()
        val sorted = nums.sortedArray()
        var good = true
        for (x in 0 until n) {
            if (x and 1 == 0) {
                if (sorted[x] != evens[x shr 1]) {
                    good = false
                }
            } else {
                if (sorted[x] != odds[x shr 1]) {
                    good = false
                }
            }
        }
        if (good) {
            sb.appendLine("YES")
        } else {
            sb.appendLine("NO")
        }
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