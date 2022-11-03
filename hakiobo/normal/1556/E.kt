import java.io.BufferedReader
import kotlin.math.absoluteValue

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val n = br.readInt()
    val q = br.readInt()
    val a = IntArray(n) { -br.readInt() }
    repeat(n) { idx ->
        a[idx] += br.readInt()
    }
    val prefix = LongArray(n + 1)
    val suffix = LongArray(n + 1)
    for (x in 1..n) {
        suffix[n - x] = suffix[n - x + 1] + a[n - x]
        prefix[x] = prefix[x - 1] + a[x - 1]
    }
//    val sparseAbs = SparseMaxAbsTable(a)
    val sparsePrefixMin = SparseMinTable(prefix)
    val sparsePrefixMax = SparseMaxTable(prefix)

//    val sparseSuffix = SparseMaxTable(suffix)
    repeat(q) {
        val l = br.readInt() - 1
        val r = br.readInt() - 1
        val ans = if (prefix[r + 1] != prefix[l]) {
            -1
        } else if (prefix[sparsePrefixMin.getMinRange(l + 1, r + 1)] - prefix[l] < 0) {
            -1
        } else {
            prefix[sparsePrefixMax.getMaxRange(l + 1, r + 1)] - prefix[l]
        }
        sb.appendLine(ans)
    }

    print(sb)
}

private class SparseMinTable(val nums: LongArray) {
    val n = nums.size
    val table = Array(
        Integer.numberOfTrailingZeros(Integer.highestOneBit((n shl 2) - 1))
    ) { IntArray(n) }

    init {
        for (x in 0 until n) {
            table[0][x] = x
        }
        for (bit in 1 until table.size) {
            val pow = 1 shl bit
            for (x in 0..n - pow) {
                val a = table[bit - 1][x]
                val b = table[bit - 1][x + (pow shr 1)]
                if (nums[a] <= nums[b]) {
                    table[bit][x] = a
                } else {
                    table[bit][x] = b
                }
            }
        }
    }

    fun getMinRange(start: Int, end: Int): Int {
        return if (start <= end) {
            val dif = end - start + 1
            val high = Integer.highestOneBit(dif)
            val bit = Integer.numberOfTrailingZeros(high)
            if (high == dif) {
                table[bit][start]
            } else {
                val a = table[bit][start]
                val b = table[bit][end - high + 1]
                if (nums[a] <= nums[b]) {
                    a
                } else {
                    b
                }
            }
        } else {
            -1
        }
    }
}

private class SparseMaxTable(val nums: LongArray) {
    val n = nums.size
    val table = Array(
        Integer.numberOfTrailingZeros(Integer.highestOneBit((n shl 2) - 1))
    ) { IntArray(n) }

    init {
        for (x in 0 until n) {
            table[0][x] = x
        }
        for (bit in 1 until table.size) {
            val pow = 1 shl bit
            for (x in 0..n - pow) {
                val a = table[bit - 1][x]
                val b = table[bit - 1][x + (pow shr 1)]
                if (nums[a] >= nums[b]) {
                    table[bit][x] = a
                } else {
                    table[bit][x] = b
                }
            }
        }
    }

    fun getMaxRange(start: Int, end: Int): Int {
        return if (start <= end) {
            val dif = end - start + 1
            val high = Integer.highestOneBit(dif)
            val bit = Integer.numberOfTrailingZeros(high)
            if (high == dif) {
                table[bit][start]
            } else {
                val a = table[bit][start]
                val b = table[bit][end - high + 1]
                if (nums[a] >= nums[b]) {
                    a
                } else {
                    b
                }
            }
        } else {
            -1
        }
    }
}

private class SparseMaxAbsTable(val nums: IntArray) {
    val n = nums.size
    val table = Array(
        Integer.numberOfTrailingZeros(Integer.highestOneBit((n shl 2) - 1))
    ) { IntArray(n) }

    init {
        for (x in 0 until n) {
            table[0][x] = x
        }
        for (bit in 1 until table.size) {
            val pow = 1 shl bit
            for (x in 0..n - pow) {
                val a = table[bit - 1][x]
                val b = table[bit - 1][x + (pow shr 1)]
                if (nums[a].absoluteValue >= nums[b].absoluteValue) {
                    table[bit][x] = a
                } else {
                    table[bit][x] = b
                }
            }
        }
    }

    fun getMaxRange(start: Int, end: Int): Int {
        return if (start <= end) {
            val dif = end - start + 1
            val high = Integer.highestOneBit(dif)
            val bit = Integer.numberOfTrailingZeros(high)
            if (high == dif) {
                table[bit][start]
            } else {
                val a = table[bit][start]
                val b = table[bit][end - high + 1]
                if (nums[a].absoluteValue >= nums[b].absoluteValue) {
                    a
                } else {
                    b
                }
            }
        } else {
            -1
        }
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