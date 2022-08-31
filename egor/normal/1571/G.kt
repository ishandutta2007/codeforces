import java.io.*
import java.util.*

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Egor Kulikov (egor@egork.net)
 */
object programkt {
    @JvmStatic
    fun main(args: Array<String>) {
        val inputStream = System.`in`
        val outputStream: OutputStream = System.out
        val `in` = InputReader(inputStream)
        val out = OutputWriter(outputStream)
        val solver = GBitvaProtivDrakona()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class GBitvaProtivDrakona {
        fun solve(testNumber: Int, `in`: InputReader, out: OutputWriter) {
            val n = `in`.readInt()
            val m = `in`.readInt()
            val tree: LongIntervalTree = object : LongIntervalTree(n + m + 1) {
                override fun joinValue(left: Long, right: Long): Long {
                    return Math.max(left, right)
                }

                override fun joinDelta(was: Long, delta: Long): Long {
                    return Math.max(was, delta)
                }

                override fun accumulate(value: Long, delta: Long, length: Int): Long {
                    return Math.max(value, delta)
                }

                override fun neutralValue(): Long {
                    return Long.MIN_VALUE / 2
                }

                override fun neutralDelta(): Long {
                    return Long.MIN_VALUE / 2
                }
            }
            tree.init()
            tree.update(m, m, 0)
            val a = arrayOfNulls<IntArray>(n)
            val b = arrayOfNulls<IntArray>(n)
            val order: MutableList<IntIntPair> = ArrayList()
            for (i in 0 until n) {
                val k = `in`.readInt()
                a[i] = `in`.readIntArray(k)
                b[i] = `in`.readIntArray(k)
                for (j in 0 until k) {
                    order.add(IntIntPair(i, j))
                }
            }
            Collections.sort(order) { o1, o2 ->
                if (b[o1.first]!![o1.second] != b[o2.first]!![o2.second]) {
                    b[o2.first]!![o2.second] - b[o1.first]!![o1.second]
                } else o1.first - o2.first
            }
            for (p in order) {
                val res = a[p.first]!![p.second] + tree.query(b[p.first]!![p.second], b[p.first]!![p.second] + p.first)
                tree.update(b[p.first]!![p.second] + p.first + 1, b[p.first]!![p.second] + p.first + 1, res)
            }
            out.printLine(tree.query(0, n + m))
        }
    }

    internal class IntIntPair(val first: Int, val second: Int) : Comparable<IntIntPair> {
        override fun equals(o: Any?): Boolean {
            if (this === o) {
                return true
            }
            if (o == null || javaClass != o.javaClass) {
                return false
            }
            val pair = o as IntIntPair
            return first == pair.first && second == pair.second
        }

        override fun hashCode(): Int {
            var result = first
            result = 31 * result + second
            return result
        }

        override fun toString(): String {
            return "($first,$second)"
        }

        override fun compareTo(o: IntIntPair): Int {
            val value = Integer.compare(first, o.first)
            return if (value != 0) {
                value
            } else Integer.compare(second, o.second)
        }

    }

    internal abstract class LongIntervalTree(size: Int, shouldInit: Boolean) : IntervalTree(size, shouldInit) {
        protected var value: LongArray = LongArray(4 * size)
        protected var delta: LongArray = LongArray(4 * size)

        protected constructor(size: Int) : this(size, true) {}

        override fun initData(size: Int, nodeCount: Int) {
            value = LongArray(nodeCount)
            delta = LongArray(nodeCount)
        }

        protected abstract fun joinValue(left: Long, right: Long): Long
        protected abstract fun joinDelta(was: Long, delta: Long): Long
        protected abstract fun accumulate(value: Long, delta: Long, length: Int): Long
        protected abstract fun neutralValue(): Long
        protected abstract fun neutralDelta(): Long
        protected fun initValue(index: Int): Long {
            return neutralValue()
        }

        override fun initAfter(root: Int, left: Int, right: Int, middle: Int) {
            value[root] = joinValue(value[2 * root + 1], value[2 * root + 2])
            delta[root] = neutralDelta()
        }

        override fun initBefore(root: Int, left: Int, right: Int, middle: Int) {}
        override fun initLeaf(root: Int, index: Int) {
            value[root] = initValue(index)
            delta[root] = neutralDelta()
        }

        override fun updatePostProcess(root: Int, left: Int, right: Int, from: Int, to: Int, delta: Long, middle: Int) {
            value[root] = joinValue(value[2 * root + 1], value[2 * root + 2])
        }

        override fun updatePreProcess(root: Int, left: Int, right: Int, from: Int, to: Int, delta: Long, middle: Int) {
            pushDown(root, left, middle, right)
        }

        protected fun pushDown(root: Int, left: Int, middle: Int, right: Int) {
            value[2 * root + 1] = accumulate(value[2 * root + 1], delta[root], middle - left + 1)
            value[2 * root + 2] = accumulate(value[2 * root + 2], delta[root], right - middle)
            delta[2 * root + 1] = joinDelta(delta[2 * root + 1], delta[root])
            delta[2 * root + 2] = joinDelta(delta[2 * root + 2], delta[root])
            delta[root] = neutralDelta()
        }

        override fun updateFull(root: Int, left: Int, right: Int, from: Int, to: Int, delta: Long) {
            value[root] = accumulate(value[root], delta, right - left + 1)
            this.delta[root] = joinDelta(this.delta[root], delta)
        }

        override fun queryPostProcess(root: Int, left: Int, right: Int, from: Int, to: Int, middle: Int, leftResult: Long,
                                      rightResult: Long): Long {
            return joinValue(leftResult, rightResult)
        }

        override fun queryPreProcess(root: Int, left: Int, right: Int, from: Int, to: Int, middle: Int) {
            pushDown(root, left, middle, right)
        }

        override fun queryFull(root: Int, left: Int, right: Int, from: Int, to: Int): Long {
            return value[root]
        }

        override fun emptySegmentResult(): Long {
            return neutralValue()
        }
    }

    internal class OutputWriter {
        private val writer: PrintWriter

        constructor(outputStream: OutputStream?) {
            writer = PrintWriter(BufferedWriter(OutputStreamWriter(outputStream)))
        }

        constructor(writer: Writer?) {
            this.writer = PrintWriter(writer)
        }

        fun close() {
            writer.close()
        }

        fun printLine(i: Long) {
            writer.println(i)
        }
    }

    internal abstract class IntervalTree(protected var size: Int, shouldInit: Boolean) {

        protected constructor(size: Int) : this(size, true) {}

        protected abstract fun initData(size: Int, nodeCount: Int)
        protected abstract fun initAfter(root: Int, left: Int, right: Int, middle: Int)
        protected abstract fun initBefore(root: Int, left: Int, right: Int, middle: Int)
        protected abstract fun initLeaf(root: Int, index: Int)
        protected abstract fun updatePostProcess(root: Int, left: Int, right: Int, from: Int, to: Int, delta: Long,
                                                 middle: Int)

        protected abstract fun updatePreProcess(root: Int, left: Int, right: Int, from: Int, to: Int, delta: Long,
                                                middle: Int)

        protected abstract fun updateFull(root: Int, left: Int, right: Int, from: Int, to: Int, delta: Long)
        protected abstract fun queryPostProcess(root: Int, left: Int, right: Int, from: Int, to: Int, middle: Int,
                                                leftResult: Long, rightResult: Long): Long

        protected abstract fun queryPreProcess(root: Int, left: Int, right: Int, from: Int, to: Int, middle: Int)
        protected abstract fun queryFull(root: Int, left: Int, right: Int, from: Int, to: Int): Long
        protected abstract fun emptySegmentResult(): Long
        fun init() {
            if (size == 0) {
                return
            }
            init(0, 0, size - 1)
        }

        private fun init(root: Int, left: Int, right: Int) {
            if (left == right) {
                initLeaf(root, left)
            } else {
                val middle = left + right shr 1
                initBefore(root, left, right, middle)
                init(2 * root + 1, left, middle)
                init(2 * root + 2, middle + 1, right)
                initAfter(root, left, right, middle)
            }
        }

        fun update(from: Int, to: Int, delta: Long) {
            update(0, 0, size - 1, from, to, delta)
        }

        protected fun update(root: Int, left: Int, right: Int, from: Int, to: Int, delta: Long) {
            if (left > to || right < from) {
                return
            }
            if (left >= from && right <= to) {
                updateFull(root, left, right, from, to, delta)
                return
            }
            val middle = left + right shr 1
            updatePreProcess(root, left, right, from, to, delta, middle)
            update(2 * root + 1, left, middle, from, to, delta)
            update(2 * root + 2, middle + 1, right, from, to, delta)
            updatePostProcess(root, left, right, from, to, delta, middle)
        }

        fun query(from: Int, to: Int): Long {
            return query(0, 0, size - 1, from, to)
        }

        protected fun query(root: Int, left: Int, right: Int, from: Int, to: Int): Long {
            if (left > to || right < from) {
                return emptySegmentResult()
            }
            if (left >= from && right <= to) {
                return queryFull(root, left, right, from, to)
            }
            val middle = left + right shr 1
            queryPreProcess(root, left, right, from, to, middle)
            val leftResult = query(2 * root + 1, left, middle, from, to)
            val rightResult = query(2 * root + 2, middle + 1, right, from, to)
            return queryPostProcess(root, left, right, from, to, middle, leftResult, rightResult)
        }

        init {
            val nodeCount = Math.max(1, Integer.highestOneBit(size) shl 2)
            initData(size, nodeCount)
            if (shouldInit) {
                init()
            }
        }
    }

    internal class InputReader(private val stream: InputStream) {
        private val buf = ByteArray(1024)
        private var curChar = 0
        private var numChars = 0
        private val filter: SpaceCharFilter? = null
        fun readIntArray(size: Int): IntArray {
            val array = IntArray(size)
            for (i in 0 until size) {
                array[i] = readInt()
            }
            return array
        }

        fun read(): Int {
            if (numChars == -1) {
                throw InputMismatchException()
            }
            if (curChar >= numChars) {
                curChar = 0
                numChars = try {
                    stream.read(buf)
                } catch (e: IOException) {
                    throw InputMismatchException()
                }
                if (numChars <= 0) {
                    return -1
                }
            }
            return buf[curChar++].toInt()
        }

        fun readInt(): Int {
            var c = read()
            while (isSpaceChar(c)) {
                c = read()
            }
            var sgn = 1
            if (c == '-'.toInt()) {
                sgn = -1
                c = read()
            }
            var res = 0
            do {
                if (c < '0'.toInt() || c > '9'.toInt()) {
                    throw InputMismatchException()
                }
                res *= 10
                res += c - '0'.toInt()
                c = read()
            } while (!isSpaceChar(c))
            return res * sgn
        }

        fun isSpaceChar(c: Int): Boolean {
            return filter?.isSpaceChar(c) ?: isWhitespace(c)
        }

        interface SpaceCharFilter {
            fun isSpaceChar(ch: Int): Boolean
        }

        companion object {
            fun isWhitespace(c: Int): Boolean {
                return c == ' '.toInt() || c == '\n'.toInt() || c == '\r'.toInt() || c == '\t'.toInt() || c == -1
            }
        }

    }
}