import java.io.BufferedReader
import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val n = br.readInt()
    val q = br.readInt()
    val s = br.readLine()
    val table = DisjoinBin(s)
    repeat(q) {
        val l = br.readInt() - 1
        val r = br.readInt() - 1
        val (z, o) = table.getRangeData(l, r)
        bw.appendLine(( max(z, o) + 1).toString())
    }

    bw.flush()
}

private class DisjoinBin(val input: String) {
    val n = Integer.highestOneBit((input.length shl 1) - 1)
    val levels = Integer.numberOfTrailingZeros(n)
    val data = IntArray(n) { idx -> if (idx < input.length) input[idx] - '0' else 0 }

    val ztable = Array(levels) { IntArray(n) }
    val otable = Array(levels) { IntArray(n) }


    init {
        for (level in 0 until levels) {
            for (block in 0 until (1 shl level)) {
                val start = block shl (levels - level)
                val end = (block + 1) shl (levels - level)
                val mid = (start + end) shr 1

                otable[level][mid] = 0
                ztable[level][mid] = 0
                for (x in mid + 1 until end) {
                    ztable[level][x] = ztable[level][x - 1] + if (data[x] == 0 && data[x - 1] == 0) 1 else 0
                    otable[level][x] = otable[level][x - 1] + if (data[x] == 1 && data[x - 1] == 1) 1 else 0
                }

                ztable[level][mid - 1] = 0
                otable[level][mid - 1] = 0

                for (x in mid - 2 downTo start) {
                    ztable[level][x] = ztable[level][x + 1] + if (data[x] == 0 && data[x + 1] == 0) 1 else 0
                    otable[level][x] = otable[level][x + 1] + if (data[x] == 1 && data[x + 1] == 1) 1 else 0
                }
            }
        }
    }

    fun getRangeData(start: Int, end: Int): Pair<Int, Int> {
        if (end < start) return getRangeData(end, start)
        if (start == end) return 0 to 0
        val level = levels - 1 - Integer.numberOfTrailingZeros(Integer.highestOneBit(start xor end))
        val block = start shr (levels - level)
        val sStart = block shl (levels - level)
        val sEnd = (block + 1) shl (levels - level)
        val mid = (sStart + sEnd) shr 1

        val z = ztable[level][start] + ztable[level][end] + if(data[mid] == 0 && data[mid - 1] == 0) 1 else 0
        val o = otable[level][start] + otable[level][end] + if(data[mid] == 1 && data[mid - 1] == 1) 1 else 0

        return z to o
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