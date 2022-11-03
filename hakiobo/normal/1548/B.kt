import java.io.BufferedReader
import kotlin.math.absoluteValue
import kotlin.math.max
import kotlin.system.exitProcess

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val nums = LongArray(n) { br.readLong() }
        var ans = 1
        if (n > 1) {
            val dif = LongArray(n - 1) { idx -> (nums[idx + 1] - nums[idx]).absoluteValue }
            val table = SparseGCDTable(dif)
            var high = 0
            for (low in 0 until n - 1) {
                if (high < low) high = low
                while (high < n - 1 && table.getGCDRange(low, high) != 1L) {
                    ans = max(ans, high - low + 2)
                    high++
                }
            }
        }
        sb.appendLine(ans)
    }
    print(sb)
}

private class SparseGCDTable(nums: LongArray) {
    val n = nums.size
    val table = Array(
        Integer.numberOfTrailingZeros(Integer.highestOneBit((n shl 2) - 1))
    ) { LongArray(n) }

    init {
        for (x in 0 until n) {
            table[0][x] = nums[x]
        }
        for (bit in 1 until table.size) {
            val pow = 1 shl bit
            var x = 0
            while (x + pow <= n) {
                table[bit][x] = gcd(table[bit - 1][x], table[bit - 1][x + (pow shr 1)])
                x++
            }
        }
    }

    fun getGCDRange(start: Int, end: Int): Long {
        return if (start <= end) {
            val dif = end - start + 1
            val high = Integer.highestOneBit(dif)
            val bit = Integer.numberOfTrailingZeros(high)
            if (high == dif) {
                table[bit][start]
            } else {
                gcd(table[bit][start], table[bit][end - high + 1])
            }
        } else {
            exitProcess(-5)
//            gcd(getGCDRange(start, n - 1), getGCDRange(0, end))
        }
    }

    fun gcd(p: Long, q: Long): Long {
        return if (p == 0L) q
        else if (q == 0L) p
        else if (p and 1L == 0L && q and 1L == 0L) gcd(p shr 1, q shr 1) shl 1
        else if (p and 1L == 0L) gcd(p shr 1, q)
        else if (q and 1L == 0L) gcd(p, q shr 1)
        else if (p > q) gcd((p - q) shr 1, q)
        else gcd(p, (q - p) shr 1)
    }
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


private fun BufferedReader.readLong(): Long {
    var ret = read().toLong()
    while (ret <= SPACE_INT) {
        ret = read().toLong()
    }
    val neg = ret == '-'.toLong()
    if (neg) {
        ret = read().toLong()
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