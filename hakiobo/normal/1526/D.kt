import java.io.BufferedReader
import kotlin.math.absoluteValue
import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    fun toIdx(c: Char): Int {
        return when (c) {
            'A' -> 0
            'N' -> 1
            'T' -> 2
            'O' -> 3
            else -> -1
        }
    }

    val chars = listOf('A', 'N', 'T', 'O')

    val permutations = listOf(
        listOf(0, 1, 2, 3),
        listOf(0, 1, 3, 2),
        listOf(0, 2, 1, 3),
        listOf(0, 2, 3, 1),
        listOf(0, 3, 1, 2),
        listOf(0, 3, 2, 1),
        listOf(1, 0, 2, 3),
        listOf(1, 0, 3, 2),
        listOf(1, 2, 0, 3),
        listOf(1, 2, 3, 0),
        listOf(1, 3, 0, 2),
        listOf(1, 3, 2, 0),
        listOf(2, 0, 1, 3),
        listOf(2, 0, 3, 1),
        listOf(2, 1, 0, 3),
        listOf(2, 1, 3, 0),
        listOf(2, 3, 0, 1),
        listOf(2, 3, 1, 0),
        listOf(3, 0, 1, 2),
        listOf(3, 0, 2, 1),
        listOf(3, 1, 0, 2),
        listOf(3, 1, 2, 0),
        listOf(3, 2, 0, 1),
        listOf(3, 2, 1, 0),
    )
    repeat(t) {
        val s = br.readLine()
        val counts = IntArray(4)
        for (c in s) {
            counts[toIdx(c)]++
        }
        var bestPermutation = 0
        var bestTime = 0L
        for (permId in 0 until 24) {
            val permutation = permutations[permId]
            var time = 0L
            val fenwick = Fenwick(s.length)
//            val times = IntArray(4)
            val curSpots = IntArray(4)
            for (x in 1 until 4) {
                curSpots[permutation[x]] = curSpots[permutation[x - 1]] + counts[permutation[x - 1]]
            }
            for (idx in s.indices) {
                val cId = toIdx(s[idx])
                val change = fenwick.get(curSpots[cId], s.lastIndex) + curSpots[cId] - idx
                if(change < 0){
                    print("no")
                }
                time += change
                fenwick.add(curSpots[cId], 1)
                curSpots[cId]++
            }
//            val time = times.sum() - times.maxOrNull()!!
            if (time > bestTime) {
                bestTime = time
                bestPermutation = permId
            }
        }
        val permutation = permutations[bestPermutation]
//        sb.append(bestTime).append(" ")
        for (x in 0 until 4) {
            sb.append(chars[permutation[x]].toString().repeat(counts[permutation[x]]))
        }
        sb.append("\n")
    }
    print(sb)
}

private class Fenwick(val size: Int) {
    private val ary = IntArray(size)

    fun add(idx: Int, v: Int) {
        var k = idx + 1
        while (k <= size) {
            ary[k - 1] += v
            k += k and -k
        }
    }

    fun set(idx: Int, v: Int) {
        add(idx, v - get(idx, idx))
    }

    fun get(idx: Int): Int {
        var k = idx + 1
        var r = 0
        while (k > 0) {
            r += ary[k - 1]
            k -= k and -k
        }
        return r
    }

    fun get(a: Int, b: Int): Int {
        return get(b) - get(a - 1)
    }

    //returns the 0 indexed index of the largest prefix sum that does not exceed the given value
    fun prefixSearch(v: Int): Int {
        var idx = 0
        var curSum = 0
        var curBit = Integer.highestOneBit(size)
        while (curBit > 0) {
            if (curBit + idx <= size) {
                if (curSum + ary[curBit + idx - 1] <= v) {
                    curSum += ary[curBit + idx - 1]
                    idx += curBit
                }
            }
            curBit = curBit shr 1
        }
        return idx - 1
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