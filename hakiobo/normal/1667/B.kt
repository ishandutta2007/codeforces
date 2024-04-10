import java.io.BufferedReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val a = LongArray(n) { br.readInt().toLong() }
        val prefix = LongArray(n + 1)
        for (i in 0 until n) {
            prefix[i + 1] = prefix[i] + a[i]
        }
        val segTree = OptimalSegment(n + 1)
        val dp = IntArray(n + 1)
        val sorted = (0..n).sortedWith { u, v ->
            if (prefix[u] == prefix[v]) {
                v.compareTo(u)
            } else {
                prefix[u].compareTo(prefix[v])
            }
        }.toIntArray()
        val revSorted = IntArray(n + 1)
        for (i in 0..n) {
            revSorted[sorted[i]] = i
        }
        segTree.setMax(revSorted[0], 0)
        for (i in 1..n) {
            dp[i] = if (a[i - 1] == 0L) {
                dp[i - 1]
            } else {
                dp[i - 1] - 1
            }

            dp[i] = max(dp[i], segTree.getMax(0, revSorted[i]) + i)

            segTree.setMax(revSorted[i], dp[i] - i)
        }
        bw.append("${dp.last()}\n")
    }
    bw.flush()
}

private class OptimalSegment(private val n: Int) {
    private val tree = IntArray(n shl 1) { Int.MIN_VALUE }

    fun setMax(index: Int, value: Int) {
        var cur = index + n
        while (cur != 0 && value > tree[cur]) {
            tree[cur] = value
            cur = cur shr 1
        }
    }


    fun getMax(begin: Int, end: Int): Int {
        var left = begin + n
        var right = end + n
        var ans = Int.MIN_VALUE
        while (left <= right) {
            if (left and 1 == 1) ans = max(ans, tree[left++])
            if (right and 1 == 0) ans = max(ans, tree[right--])
            left = left shr 1
            right = right shr 1
        }
        return ans
    }
}

//private class OptimalSegment(prefix: LongArray) {
//    private val n = Integer.highestOneBit((prefix.size shl 1) - 1)
//    private val mins = LongArray(n shl 1)
//
//    init {
//        for (i in prefix.indices) {
//            mins[i + n] = prefix[i]
//        }
//        for (i in n - 1 downTo 1) {
//            mins[i] = min(mins[i.left()], mins[i.right()])
//        }
//    }
//
//    fun get(end: Int, v: Long): Int {
//        return get(0, end, 1, 0, n - 1, v)
//    }
//
//    private fun get(beginTot: Int, endTot: Int, id: Int, begin: Int, end: Int, v: Long): Int {
//        val d = (begin + end) shr 1
//        if (begin > endTot) return -1
//        return if (begin == end) {
//            begin
//        } else {
//            if (mins[id.left()] < v) {
//                get(beginTot, endTot, id.left(), begin, d, v)
//            } else if (mins[id.right()] < v) {
//                get(beginTot, endTot, id.right(), d + 1, end, v)
//            } else {
//                -1
//            }
//        }
//    }
//
//    private fun Int.right() = (this shl 1) + 1
//    private fun Int.left() = this shl 1
//}

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