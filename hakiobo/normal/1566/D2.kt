import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val m = br.readInt()
        val a = IntArray(n * m) { br.readInt() }
        val fen = SeatingFenwick(n * m)
        var ans = 0L
        val sorted = IntArray(n * m) { it }.sortedBy { idx -> a[idx] }
        val sorted2 = IntArray(n * m) { it }.sortedBy { idx -> sorted[idx] }
//        val occupied = BooleanArray(n * m)
        for (person in 0 until n * m) {
            val seat = sorted2[person]
            val row = seat / m
            ans += fen.get(row * m, seat)
            fen.add(seat, 1)
        }
        for (row in 0 until n) {
            var prevSight = a[sorted[row * m]]
            var size = 1
            for (col in 1 until m) {
                val sight = a[sorted[row * m + col]]
                if (sight == prevSight) {
                    size++
                } else {
                    ans -= ((size) * (size - 1)) shr 1
                    prevSight = sight
                    size = 1
                }
            }
            ans -= ((size) * (size - 1)) shr 1

        }
        sb.appendLine(ans)

    }
    print(sb)
}

private class SeatingFenwick(val size: Int) {
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