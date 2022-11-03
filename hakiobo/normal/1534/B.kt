import java.io.BufferedReader
import kotlin.math.absoluteValue
import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val nums = LongArray(n) { br.readInt().toLong() }
        fun getNumAbove(idx: Int): Long {
            return if (idx == n - 1) {
                0L
            } else {
                nums[idx + 1]
            }
        }

        fun getNumBelow(idx: Int): Long {
            return if (idx == 0) {
                0L
            } else {
                nums[idx - 1]
            }
        }

        var ans = nums.first()
        for (x in 0 until n) {
            ans += (nums[x] - getNumAbove(x)).absoluteValue
            val dif = nums[x] - max(getNumAbove(x), getNumBelow(x))
            if (dif > 0) {
                nums[x] -= dif
                ans -= dif
            }
        }
        sb.appendLine(ans)
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