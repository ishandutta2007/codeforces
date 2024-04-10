import java.lang.System.`in`
import kotlin.math.max

fun main() {
    val br = `in`.bufferedReader()
    val sb = StringBuilder()
    val numNums = br.readLine().toInt()
    val p = br.readLine().split(' ').map(String::toInt)
    val q = br.readLine().split(' ').map(String::toInt)
    val revP = IntArray(numNums)
    p.forEachIndexed { id, it -> revP[it - 1] = id }
    val segment = BombMaxSegment(numNums)
    var score = numNums
    segment.update(0, revP[score - 1], 1)
    q.forEach {
        while (segment.get(0, numNums - 1) <= 0) {
            score--
            segment.update(0, revP[score - 1], 1)
        }
        sb.append(score)
        sb.append(' ')
        segment.update(0, it - 1, -1)
    }

    print(sb)
}

private class BombMaxSegment(val n: Int) {
    private val size = Integer.highestOneBit(n - 1) shl 1
    private val tree = IntArray(size shl 1)
    private val updates = IntArray(size shl 1)

    fun update(begin: Int, end: Int, update: Int) {
        update(begin, end, update, 1, 0, size - 1)
    }

    private fun update(beginTot: Int, endTot: Int, update: Int, id: Int, begin: Int, end: Int) {
        propogateUpdate(id)
        if (endTot < begin || beginTot > end) return
        if (end <= endTot && begin >= beginTot) {
            updates[id] += update
            return
        }
        val d = (begin + end) shr 1
        update(beginTot, endTot, update, id shl 1, begin, d)
        update(beginTot, endTot, update, (id shl 1) + 1, d + 1, end)
        tree[id] = max(tree[id shl 1] + updates[id shl 1], tree[(id shl 1) + 1] + updates[(id shl 1) + 1])
    }

    fun get(begin: Int, end: Int): Int {
        return get(begin, end, 1, 0, size - 1)
    }

    private fun get(beginTot: Int, endTot: Int, id: Int, begin: Int, end: Int): Int {
        propogateUpdate(id)
        if (endTot < begin || beginTot > end) return Int.MIN_VALUE
        if (end <= endTot && begin >= beginTot) return tree[id]
        val d = (begin + end) shr 1
        return max(get(beginTot, endTot, id shl 1, begin, d), get(beginTot, endTot, (id shl 1) + 1, d + 1, end))
    }

    private fun propogateUpdate(id: Int){
        if(updates[id] != 0){
            tree[id] += updates[id]
            if (id < size) {
                updates[id shl 1] += updates[id]
                updates[(id shl 1) + 1] += updates[id]
            }
            updates[id] = 0
        }
    }
}