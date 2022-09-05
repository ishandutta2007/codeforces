import java.io.PrintWriter
import java.util.*
import javax.swing.text.Segment
import kotlin.collections.ArrayList

@JvmField val INPUT = System.`in`
@JvmField val OUTPUT = System.out

@JvmField val _reader = INPUT.bufferedReader()
fun readLine(): String? = _reader.readLine()
fun readLn() = _reader.readLine()!!
@JvmField var _tokenizer: StringTokenizer = StringTokenizer("")
fun read(): String {
    while (_tokenizer.hasMoreTokens().not()) _tokenizer = StringTokenizer(_reader.readLine() ?: return "", " ")
    return _tokenizer.nextToken()
}
fun readInt() = read().toInt()
fun readDouble() = read().toDouble()
fun readLong() = read().toLong()
fun readStrings(n: Int) = List(n) { read() }
fun readLines(n: Int) = List(n) { readLn() }
fun readInts(n: Int) = List(n) { read().toInt() }
fun readIntArray(n: Int) = IntArray(n) { read().toInt() }
fun readDoubles(n: Int) = List(n) { read().toDouble() }
fun readDoubleArray(n: Int) = DoubleArray(n) { read().toDouble() }
fun readLongs(n: Int) = List(n) { read().toLong() }
fun readLongArray(n: Int) = LongArray(n) { read().toLong() }

@JvmField val _writer = PrintWriter(OUTPUT, false)
inline fun output(block: PrintWriter.() -> Unit) { _writer.apply(block).flush() }

class SegmentTreeLazyProp {

    private val tree: LongArray
    private val lazy: LongArray
    private val len: Int

    /**
     * Fills the segment tree, based on input list
     *
     * @param list Used to construct the initial tree
     */
    constructor(list: List<Int>) {
        tree = LongArray(list.size * 4)
        lazy = LongArray(tree.size)
        len = list.size
        build(list = list)
    }

    /**
     * Creates an empty segment tree
     *
     * @param size Size of relevant range
     */
    constructor(size: Int) {
        tree = LongArray(size * 4)
        lazy = LongArray(tree.size)
        len = size
    }

    /**
     * Builds the segment tree with values from input list.
     *
     * @param list Int list used to fill the tree
     * @param ind Current index / node of the segment tree
     * @param segLeft Left end of current segment
     * @param segRight Right end of current segment
     */
    private fun build(list: List<Int>, ind: Int = 1, segLeft: Int = 1, segRight: Int = len) {
        if (segLeft == segRight) {
            tree[ind] = list[segLeft-1].toLong()
        } else {
            val mid = (segLeft + segRight) / 2
            build(list, ind * 2, segLeft, mid)
            build(list, ind * 2 + 1, mid + 1, segRight)
            tree[ind] = tree[ind * 2] + tree[ind * 2 + 1]
        }
    }

    /**
     * Updates the segment tree. Updates the nodes for a given range with a new value.
     *
     * @param ind Current index / node to update in the tree
     * @param value Adding this value to a given range
     * @param segLeft Left end of current segment
     * @param segRight Right end of current segment
     * @param left Left end of the update range
     * @param right Right end of the update range
     */
    fun update(ind: Int = 1, value: Long, segLeft: Int = 1, segRight: Int = len, left: Int, right: Int) {
        propagateToChildren(ind, segLeft, segRight)
        if (segLeft > right || segRight < left || segLeft > segRight) {
            return
        }
        if (left <= segLeft && segRight <= right) {
            tree[ind] = value * (segRight - segLeft + 1).toLong()
            if (segLeft != segRight) {
                lazy[ind * 2] = value
                lazy[ind * 2 + 1] = value
            }
        } else {
            val mid = (segLeft + segRight) / 2
            update(ind * 2, value, segLeft, mid, left, right)
            update(ind * 2 + 1, value, mid + 1, segRight, left, right)
            tree[ind] = tree[ind * 2] + tree[ind * 2 + 1]
        }
    }

    /**
     * Get the sum of a given range in the tree.
     *
     * @param ind Current index / node of the segment tree
     * @param segLeft Left end of current segment
     * @param segRight Right end of current segment
     * @param left Left end of the query range
     * @param right Right end of the query range
     * @return sum of the range
     */
    fun get(ind: Int = 1, segLeft: Int = 1, segRight: Int = len, left: Int, right: Int): Long {
        if (segLeft > right || segRight < left || segLeft > segRight) {
            return 0L
        }
        propagateToChildren(ind, segLeft, segRight)
        if (left <= segLeft && segRight <= right) {
            return tree[ind]
        }
        val mid = (segLeft + segRight) / 2
        val leftValue = get(ind * 2, segLeft, mid, left, right)
        val rightValue = get(ind * 2 + 1, mid + 1, segRight, left, right)
        return leftValue + rightValue
    }

    /**
     * Updates current node if current node is flagged as lazy, meaning
     * its lazy value is not zero. Laziness is then propagated from current node to its children
     *
     * @param ind Current index / node of the segment tree
     * @param segLeft Left end of current segment
     * @param segRight Right end of current segment
     */
    private fun propagateToChildren(ind: Int, segLeft: Int, segRight: Int) {
        if (lazy[ind] != 0L) {
            tree[ind] = lazy[ind] * (segRight - segLeft + 1)
            if (segLeft != segRight) {
                lazy[ind * 2] = lazy[ind]
                lazy[ind * 2 + 1] = lazy[ind]
            }
            lazy[ind] = 0L
        }
    }
}

fun main(args: Array<String>) {

    var tt = 1
    for (qq in 0 until tt) {
         var N = readInt()
        var seg = SegmentTreeLazyProp(N)
        var lst = TreeMap<Int, Long>()
        var A = readLongArray(N)
        lst[-1] = 10000000
        var lstHigher = IntArray(N)

        var qs = Array<ArrayList<Pair<Int, Int>>>(N, {it -> ArrayList() })
        var Q = readInt()
        for (i in 0 until Q) {
            var (X, Y) = readInts(2)
            X--
            Y--
            qs[Y].add(Pair<Int, Int>(X, i))
        }
        var ans = LongArray(Q)
        for (i in 0 until N) {
            while (lst[lst.lowerKey(i)?:0]!! < A[i]) {
                lst.remove(lst.lowerKey(i)?:0)
            }
            lstHigher[i] = lst.lowerKey(i)?:0
            lstHigher[i]++
            seg.update(value = A[i], left = lstHigher[i]+1, right = i+1)
            /*for (j in 0 until i+1) {
                print("" + seg.get(left = j, right = j) + " ")
            }
            println()*/
            lst.put(i, A[i])
            for (j in 0 until qs[i].size) {
                ans[qs[i][j].second] = seg.get(left = qs[i][j].first+1, right=i+1)
            }
        }
        for (i in 0 until Q) {
            print("" + ans[i] + " ")
        }
        println()


    }
}