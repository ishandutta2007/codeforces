import java.io.BufferedReader
import java.util.TreeMap

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val k = br.readInt()
        val counts = IntArray(n)
        val others = TreeMap<Int, Int>()
        val nums = IntArray(n) { br.readInt() }.sorted().toIntArray()
        var excessWithin = 0
        val countsByCount = IntArray(n + 1)
        var movesLeft = k
        var lookingFor = 0
        var curCt = 0
        var distinctAbove = 0
        for (i in nums.indices) {
            val num = nums[i]
            while (movesLeft >= 0 && lookingFor < num) {
                movesLeft--
                lookingFor++
            }
            if (movesLeft >= 0) {
                if (lookingFor == num) {
                    lookingFor++
                } else {
                    excessWithin++
                }
            } else {
                if (i > 0 && nums[i] == nums[i - 1]) {
                    curCt++
                } else {
                    distinctAbove++
                    countsByCount[curCt]++
                    curCt = 1
                }
            }
        }
        countsByCount[curCt]++
        var curSize = 1
        movesLeft = k
        while (movesLeft >= curSize && curSize <= n) {
            if (countsByCount[curSize] != 0) {
                countsByCount[curSize]--
                movesLeft -= curSize
                distinctAbove--
            } else {
                curSize++
            }
        }
        bw.appendLine(distinctAbove.toString())

    }
    bw.flush()
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