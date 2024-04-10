import java.io.BufferedReader
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val c = br.readInt()
//        val fen = BFenwick(c)
        val prefix = IntArray(c + 1)
        val inArray = BooleanArray(c)
        repeat(n) {
            val num = br.readInt()
            inArray[num - 1] = true
            prefix[num]++
        }
        for (x in 1..c) {
            prefix[x] += prefix[x - 1]
        }
        var good = true
        var i = 2
        if (!inArray[0]) good = false
        while (i <= c && good) {
            if (inArray[i - 1]) {
                var k = 2

                while (k * i <= c) {
                    val low = k * i - 1
                    val high = min((k + 1) * i - 1, c)
                    if (prefix[high] - prefix[low] != 0) {
                        if (!inArray[k - 1]) good = false
                    }

                    k++
                }
            }
            i++
        }
        if (good) {
            bw.append("Yes\n")
        } else {
            bw.append("No\n")
        }

    }
    bw.flush()
}

private class BFenwick(val size: Int) {
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