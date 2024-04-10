import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val nums = IntArray(n) { br.readInt() }.sortedArray()
        if (n == 2) {
            sb.appendLine(nums.joinToString(" "))
        } else {
            var bestIdx = 1
            for (x in 2 until n) {
                if (nums[x] - nums[x - 1] < nums[bestIdx] - nums[bestIdx - 1]) {
                    bestIdx = x
                }
            }
            val answer = IntArray(n) { idx ->
                nums[(bestIdx + idx) % n]
            }
            sb.appendLine(answer.joinToString(" "))
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