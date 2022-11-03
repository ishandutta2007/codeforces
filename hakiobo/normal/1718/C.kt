import java.io.BufferedReader
import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val q = br.readInt()
        val primesInit = mutableListOf<Int>()
        var num = n
        var curTest = 2
        while (curTest * curTest <= num) {
            if (num % curTest == 0) {
                primesInit += n / curTest
                while (num % curTest == 0) num /= curTest
            }
            curTest++
        }
        if (num != 1) primesInit += n / num
        val primes = primesInit.toIntArray()
        val data = Array(primes.size) { i -> LongArray(primes[i]) }
        val nums = LongArray(n) { br.readInt().toLong() }
        for (i in 0 until n) {
            for (j in primes.indices) {
                val f = primes[j]
                data[j][i % f] += f * nums[i]
            }
        }
        val trees = Array(primes.size) { i -> BurenkaSegTree(data[i].size, data[i]) }
        var best = 0L
        for (tree in trees) {
            best = max(best, tree.getMax(0, tree.n - 1))
        }
        bw.appendLine("$best")
        repeat(q) {
            val p = br.readInt() - 1
            val x = br.readInt().toLong()
            val old = nums[p]
            nums[p] = x
            best = 0
            for (i in primes.indices) {
                val f = primes[i]
                val j = p % f
                data[i][j] += (x - old) * f
                trees[i].set(j, data[i][j])
                best = max(best, trees[i].getMax(0, trees[i].n - 1))
            }
            bw.appendLine("$best")
        }
    }
    bw.flush()
}

private class BurenkaSegTree(val n: Int, base: LongArray) {
    private val tree = LongArray(n shl 1)

    init {
        for (i in n until (n shl 1)) {
            tree[i] = base[i - n]
        }
        for (i in n - 1 downTo 1) {
            tree[i] = max(tree[i.left()], tree[i.right()])
        }
    }

    fun set(index: Int, value: Long) {
        var cur = index + n
        tree[cur] = value
        while (cur != 1) {
            cur = cur shr 1
            tree[cur] = max(tree[cur.left()], tree[cur.right()])
        }
    }

    fun getMax(begin: Int, end: Int): Long {
        var left = begin + n
        var right = end + n
        var ans = 0L
        while (left <= right) {
            if (left and 1 == 1) ans = max(ans, tree[left++])
            if (right and 1 == 0) ans = max(ans, tree[right--])
            left = left shr 1
            right = right shr 1
        }
        return ans
    }

    private fun Int.right() = (this shl 1) + 1
    private fun Int.left() = this shl 1
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