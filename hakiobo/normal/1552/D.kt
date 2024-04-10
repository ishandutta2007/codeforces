import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val a = IntArray(n) { br.readInt() }
        var good = false
        for (mask in 1 until (1 shl n)) {
            for (adjustments in 0 until (1 shl mask.countOneBits())) {
                var sum = 0
                var s = mask
                var bIdx = 0
                while (s != 0) {
                    val idx = s.countTrailingZeroBits()
                    sum += a[idx] * if ((1 shl bIdx) and adjustments == 0) 1 else -1
                    bIdx++
                    s = s xor (1 shl idx)
                }
                if (sum == 0) good = true
            }
        }
        if (good) sb.appendLine("YES") else sb.appendLine("NO")
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