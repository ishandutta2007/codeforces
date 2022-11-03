import java.io.BufferedReader

fun main() {
    val maxV = 300_000
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val n = br.readInt()
    val a = LongArray(n) { br.readInt().toLong() }
    val prefix = LongArray(n + 1)
    for (x in 0 until n) {
        prefix[x + 1] = prefix[x] + a[x]
    }

//    val sorted = IntArray(n) { idx -> idx }.sortedBy { x -> a[x] }.toIntArray()
    val fenwick = Fenwick(maxV + 1)
    val fenwick2 = Fenwick(maxV + 1)
    var ans = 0L
    for (x in 0 until n) {
        val num = a[x].toInt()
        ans += prefix[x] + a[x] * x + fenwick2.get(num)
        var check = num
        while (check <= maxV) {
            ans -= num * fenwick.get(check, maxV)
            fenwick2.add(check, -a[x])
            check += num
        }
        fenwick.add(num, 1)
        sb.append("$ans ")
    }
    print(sb)
}

private class Fenwick(val size: Int) {
    private val ary = LongArray(size)

    fun add(idx: Int, v: Long) {
        var k = idx + 1
        while (k <= size) {
            ary[k - 1] += v
            k += k and -k
        }
    }

    fun set(idx: Int, v: Long) {
        add(idx, v - get(idx, idx))
    }

    fun get(idx: Int): Long {
        var k = idx + 1
        var r = 0L
        while (k > 0) {
            r += ary[k - 1]
            k -= k and -k
        }
        return r
    }

    fun get(a: Int, b: Int): Long {
        return get(b) - get(a - 1)
    }

    //returns the 0 indexed index of the largest prefix sum that does not exceed the given value
//    fun prefixSearch(v: Int): Int {
//        var idx = 0
//        var curSum = 0
//        var curBit = Integer.highestOneBit(size)
//        while (curBit > 0) {
//            if (curBit + idx <= size) {
//                if (curSum + ary[curBit + idx - 1] <= v) {
//                    curSum += ary[curBit + idx - 1]
//                    idx += curBit
//                }
//            }
//            curBit = curBit shr 1
//        }
//        return idx - 1
//    }
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