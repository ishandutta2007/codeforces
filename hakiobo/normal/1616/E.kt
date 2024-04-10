import java.io.BufferedReader
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val q = br.readInt()

    fun solve(): Long {
        val n = br.readInt()
        val s = br.readLine()
        val t = br.readLine()
        val used = BooleanArray(n)
        var ans = Long.MAX_VALUE
        val nextLarger = Array(26) { IntArray(n + 1) { n } }
        for (x in n - 1 downTo 0) {
            val c = s[x] - 'a'
            for (y in 0 until c) {
                nextLarger[y][x] = nextLarger[y][x + 1]
            }
            for (y in c until 26) {
                nextLarger[y][x] = x
            }
        }
        val indices = IntArray(26)
        fun findNextOfOrSmaller(c: Int): Int {
            var ret = nextLarger[c][indices[c]]
            while (ret < n && used[ret]) {
                indices[c] = ret + 1
                ret = nextLarger[c][indices[c]]
            }
            return ret
        }

        val fenwick = SmallEnoughFenwick(n)

        fun calc(tIdx: Int, i: Int): Int {
            return i - tIdx + fenwick.get(i + 1, n - 1)
        }

        var curMoves = 0L
        for (x in 0 until n) {
            if (ans <= curMoves) break
            val c = t[x] - 'a'
            if (c > 0) {
                val next = findNextOfOrSmaller(c - 1)
                if (next != n) {
                    ans = min(ans, curMoves + calc(x, next))
                }
            }
            val next = findNextOfOrSmaller(c)
            if (next != n) {
                used[next] = true
                curMoves += calc(x, next)
                fenwick.add(next, 1)
            } else {
                break
            }
        }
        return if (ans == Long.MAX_VALUE) {
            -1
        } else {
            ans
        }
    }

    repeat(q) {
        sb.appendLine(solve())
    }
    println(sb)
}


private class SmallEnoughFenwick(val size: Int) {
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