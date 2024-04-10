import java.io.BufferedReader

private fun minLeft(r: Int, minTable: PermutationMinTable, maxTable: PermutationMaxTable, n: Int): Int {
    if (r == -1) return 0
    val low = minTable.getMinRange(0, r)
    return 1 + maxLeft(low - 1, minTable, maxTable, n)
}

private fun maxLeft(r: Int, minTable: PermutationMinTable, maxTable: PermutationMaxTable, n: Int): Int {
    if (r == -1) return 0
    val high = maxTable.getMaxRange(0, r)
    return 1 + minLeft(high - 1, minTable, maxTable, n)
}

private fun minRight(l: Int, minTable: PermutationMinTable, maxTable: PermutationMaxTable, n: Int): Int {
    if (l == n) return 0
    val low = minTable.getMinRange(l, n - 1)
    return 1 + maxRight(low + 1, minTable, maxTable, n)
}

private fun maxRight(l: Int, minTable: PermutationMinTable, maxTable: PermutationMaxTable, n: Int): Int {
    if (l == n) return 0
    val high = maxTable.getMaxRange(l, n - 1)
    return 1 + minRight(high + 1, minTable, maxTable, n)
}

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val a = IntArray(n) { br.readInt() - 1 }
        val minTable = PermutationMinTable(a)
        val maxTable = PermutationMaxTable(a)
        val lowest = minTable.getMinRange(0, n - 1)
        val ans = maxLeft(lowest - 1, minTable, maxTable, n) + maxRight(lowest + 1, minTable, maxTable, n)
        bw.appendLine("$ans")
    }
    bw.flush()
}

private class PermutationMinTable(val nums: IntArray) {
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

private class PermutationMaxTable(val nums: IntArray) {
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