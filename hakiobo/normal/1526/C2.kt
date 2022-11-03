import java.io.BufferedReader
import kotlin.math.max
import kotlin.math.min
import kotlin.system.exitProcess

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val nums = List<Long>(n) { br.readInt().toLong() }.withIndex()
    val segment = PotionsSegment(n)
    var ans = 0
    for ((idx, num) in nums) {
        if (num >= 0L) {
            segment.update(idx, n - 1, num)
            ans++
        }
    }
    nums.filter { it.value < 0 }.sortedBy { -it.value }.forEach { (idx, num) ->
        segment.update(idx, n - 1, num)
        val check = segment.get(0, n - 1)
        if (check < 0L) {
            segment.update(idx, n - 1, -num)
        } else {
            ans++
        }
    }


    print(ans)
}

private class PotionsSegment(n: Int) {
    private val size = max(1, Integer.highestOneBit(n - 1)) shl 1
    private val tree = LongArray(size shl 1)
    private val updates = LongArray(size shl 1)

    fun update(begin: Int, end: Int, update: Long) {
        update(begin, end, update, 1, 0, size - 1)
    }

    private fun update(beginTot: Int, endTot: Int, update: Long, id: Int, begin: Int, end: Int) {
        propogateUpdate(id)
        if (endTot < begin || beginTot > end) return
        if (end <= endTot && begin >= beginTot) {
            updates[id] += update
            return
        }
        val d = (end - begin) shr 1
        update(beginTot, endTot, update, id shl 1, begin, begin + d)
        update(beginTot, endTot, update, (id shl 1) + 1, begin + d + 1, end)
        tree[id] = min(tree[id shl 1] + updates[id shl 1], tree[(id shl 1) + 1] + updates[(id shl 1) + 1])
    }

    fun get(begin: Int, end: Int): Long {
        return get(begin, end, 1, 0, size - 1)
    }

    private fun get(beginTot: Int, endTot: Int, id: Int, begin: Int, end: Int): Long {
        propogateUpdate(id)
        if (endTot < begin || beginTot > end) return Long.MAX_VALUE
        if (end <= endTot && begin >= beginTot) return tree[id]
        val d = (end - begin) shr 1
        return min(
            get(beginTot, endTot, id shl 1, begin, begin + d),
            get(beginTot, endTot, (id shl 1) + 1, end - d, end)
        )
    }

    private fun propogateUpdate(id: Int) {
        if (id < 0) exitProcess(0)
        if (updates[id] != 0L) {
            tree[id] += updates[id]
            if (id < size) {
                updates[id shl 1] += updates[id]
                updates[(id shl 1) + 1] += updates[id]
            }
            updates[id] = 0L
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