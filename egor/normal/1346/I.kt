import java.io.OutputStream
import java.io.IOException
import java.io.InputStream
import java.io.PrintWriter
import java.util.Arrays
import java.io.BufferedWriter
import java.util.NavigableSet
import java.util.InputMismatchException
import java.util.TreeSet
import java.util.ArrayList
import java.io.Writer
import java.io.OutputStreamWriter
import java.util.Comparator
import java.util.Collections

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
        val outputStream = System.out
        val `in` = InputReader(inputStream)
        val out = OutputWriter(outputStream)
        val solver = IPacMan20()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class IPacMan20 {
        var powers: MutableList<Array<LongArray>> = ArrayList()

        fun multiply(c: Array<LongArray>, a: Array<LongArray>, b: Array<LongArray>) {
            ArrayUtils.fill(c, java.lang.Long.MAX_VALUE / 2)
            for (i in a.indices) {
                for (j in b.indices) {
                    for (k in a.indices) {
                        c[i][k] = Math.min(c[i][k], a[i][j] + b[j][k])
                    }
                }
            }
        }

        fun power(result: Array<LongArray>, temp: Array<LongArray>, mat: Array<LongArray>, exponent: Long) {
            var result = result
            var temp = temp
            var exponent = exponent
            ArrayUtils.fill(result, java.lang.Long.MAX_VALUE / 2)
            for (i in result.indices) {
                result[i][i] = 0
            }
            var times = 0
            run {
                var i = 0
                while (exponent != 0L) {
                    if (exponent shr i and 1 == 1L) {
                        while (powers.size <= i) {
                            val next = Array(result.size) { LongArray(result.size) }
                            multiply(next, powers[powers.size - 1], powers[powers.size - 1])
                            powers.add(next)
                        }
                        multiply(temp, result, powers[i])
                        exponent -= 1L shl i
                        val a = temp
                        temp = result
                        result = a
                        times++
                    }
                    i++
                }
            }
            if (times % 2 == 1) {
                for (i in result.indices) {
                    for (j in result.indices) {
                        temp[i][j] = result[i][j]
                    }
                }
            }
        }

        fun solve(testNumber: Int, `in`: InputReader, out: OutputWriter) {
            val n = `in`.readInt()
            val m = `in`.readInt()
            val q = `in`.readInt()
            val s = `in`.readInt() - 1
            val a = `in`.readIntArray(n)
            val u = IntArray(m)
            val v = IntArray(m)
            `in`.readIntArrays(u, v)
            MiscUtils.decreaseByOne(u, v)
            val c = `in`.readLongArray(q)

            val graph = Graph(n, m)
            for (i in 0 until m) {
                graph.addSimpleEdge(u[i], v[i])
            }
            val minSteps = Array(n) { Array(n) { IntArray(1 shl n) } }
            val inf = Integer.MAX_VALUE / 2
            ArrayUtils.fill(minSteps, inf)
            val sum = LongArray(1 shl n)
            for (i in sum.indices) {
                for (j in 0 until n) {
                    if (i shr j and 1 == 1) {
                        sum[i] += a[j].toLong()
                    }
                }
            }
            val best = Array(n) { LongArray(n * n + 1) }
            for (i in 0 until n) {
                val finalI = i
                val queue = TreeSet(
                        Comparator<IntIntPair> { x, y ->
                            val delta = minSteps[finalI][x.first][x.second] - minSteps[finalI][y.first][y.second]
                            if (delta != 0) {
                                return@Comparator delta
                            }
                            if (x.first != y.first) {
                                x.first - y.first
                            } else x.second - y.second
                        })
                minSteps[i][i][1 shl i] = 0
                queue.add(IntIntPair(i, 1 shl i))
                while (!queue.isEmpty()) {
                    val cur = queue.pollFirst()
                    val `val` = minSteps[i][cur!!.first][cur.second]
                    best[i][`val`] = Math.max(best[i][`val`], sum[cur.second])
                    var j = graph.firstOutbound(cur.first)
                    while (j != -1) {
                        val to = graph.destination(j)
                        val cVal = minSteps[i][to][cur.second or (1 shl to)]
                        if (cVal > `val` + 1) {
                            val key = IntIntPair(to, cur.second or (1 shl to))
                            if (cVal != inf) {
                                queue.remove(key)
                            }
                            minSteps[i][to][key.second] = `val` + 1
                            queue.add(key)
                        }
                        j = graph.nextOutbound(j)
                    }
                }
                for (j in 1..n * n) {
                    best[i][j] = Math.max(best[i][j], best[i][j - 1])
                }
            }
            //        System.err.println("Precalc");
            val steps = Array(n) { LongArray(n) }
            for (i in 0 until n) {
                for (j in 0 until n) {
                    steps[i][j] = minSteps[i][j][(1 shl n) - 1].toLong()
                }
            }
            var cur = Array(n) { LongArray(n) }
            ArrayUtils.fill(cur, java.lang.Long.MAX_VALUE / 2)
            for (i in cur.indices) {
                cur[i][i] = 0
            }
            powers.add(steps)
            val result = Array(n) { LongArray(n) }
            var temp = Array(n) { LongArray(n) }
            var lastExp: Long = 0
            val order = ArrayList<Int>()
            for (i in 0 until q) {
                order.add(i)
            }
            Collections.sort(order) { o1, o2 -> java.lang.Long.compare(c[o1], c[o2]) }
            val res = LongArray(q)
            for (i in order) {
                val exponent = c[i] / sum[(1 shl n) - 1]
                if (exponent != lastExp) {
                    power(result, temp, steps, exponent - lastExp)
                    lastExp = exponent
                    multiply(temp, cur, result)
                    val x = temp
                    temp = cur
                    cur = x
                }
                c[i] %= sum[(1 shl n) - 1]
                var answer = java.lang.Long.MAX_VALUE
                for (j in 0 until n) {
                    for (k in 0..n * n) {
                        if (best[j][k] >= c[i]) {
                            answer = Math.min(answer, cur[s][j] + k)
                            break
                        }
                    }
                }
                res[i] = answer
            }
            for (l in res) {
                out.printLine(l)
            }
        }

    }

    internal class InputReader(private val stream: InputStream) {
        private val buf = ByteArray(1024)
        private var curChar: Int = 0
        private var numChars: Int = 0
        private val filter: InputReader.SpaceCharFilter? = null

        fun readIntArrays(vararg arrays: IntArray) {
            for (i in 0 until arrays[0].size) {
                for (j in arrays.indices) {
                    arrays[j][i] = readInt()
                }
            }
        }

        fun readLongArray(size: Int): LongArray {
            val array = LongArray(size)
            for (i in 0 until size) {
                array[i] = readLong()
            }
            return array
        }

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
                try {
                    numChars = stream.read(buf)
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

        fun readLong(): Long {
            var c = read()
            while (isSpaceChar(c)) {
                c = read()
            }
            var sgn = 1
            if (c == '-'.toInt()) {
                sgn = -1
                c = read()
            }
            var res: Long = 0
            do {
                if (c < '0'.toInt() || c > '9'.toInt()) {
                    throw InputMismatchException()
                }
                res *= 10
                res += (c - '0'.toInt()).toLong()
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

    internal class Graph @JvmOverloads constructor(protected var vertexCount: Int, edgeCapacity: Int = vertexCount) {
        protected var edgeCount: Int = 0
        private var firstOutbound = EMPTY_INT
        private val firstInbound = EMPTY_INT
        private val edges = EMPTY_EDGE
        private val nextInbound = EMPTY_INT
        private var nextOutbound = EMPTY_INT
        private var from = EMPTY_INT
        private var to = EMPTY_INT
        private var weight = EMPTY_LONG
        var capacity = EMPTY_LONG
        private var reverseEdge = EMPTY_INT
        private var flags = EMPTY_INT
        private val edgesInit = false
        private val inboundInit = false
        private var weightInit = false
        private var capacityInit = false

        init {
            firstOutbound = IntArray(vertexCount)
            Arrays.fill(firstOutbound, -1)

            from = IntArray(edgeCapacity)
            to = IntArray(edgeCapacity)
            nextOutbound = IntArray(edgeCapacity)
            flags = IntArray(edgeCapacity)
        }

        fun addEdge(fromID: Int, toID: Int, weight: Long, capacity: Long, reverseEdge: Int): Int {
            ensureEdgeCapacity(edgeCount + 1)
            if (firstOutbound[fromID] != -1) {
                nextOutbound[edgeCount] = firstOutbound[fromID]
            } else {
                nextOutbound[edgeCount] = -1
            }
            firstOutbound[fromID] = edgeCount
            if (inboundInit) {
                if (firstInbound[toID] != -1) {
                    nextInbound[edgeCount] = firstInbound[toID]
                } else {
                    nextInbound[edgeCount] = -1
                }
                firstInbound[toID] = edgeCount
            }
            this.from[edgeCount] = fromID
            this.to[edgeCount] = toID
            if (capacity != 0L) {
                if (!capacityInit) {
                    capacityInit = true
                    this.capacity = LongArray(from.size)
                    this.reverseEdge = IntArray(from.size)
                    Arrays.fill(this.reverseEdge, 0, edgeCount, -1)
                }
                this.capacity[edgeCount] = capacity
            }
            if (weight != 0L) {
                if (!weightInit) {
                    weightInit = true
                    this.weight = LongArray(from.size)
                }
                this.weight[edgeCount] = weight
            }
            if (reverseEdge != -1) {
                this.reverseEdge[edgeCount] = reverseEdge
            }
            if (edgesInit) {
                edges[edgeCount] = createEdge(edgeCount)
            }
            return edgeCount++
        }

        protected fun createEdge(id: Int): GraphEdge {
            return GraphEdge(id)
        }

        fun addFlowWeightedEdge(from: Int, to: Int, weight: Long, capacity: Long): Int {
            if (capacity == 0L) {
                return addEdge(from, to, weight, 0, -1)
            } else {
                val lastEdgeCount = edgeCount
                addEdge(to, from, -weight, 0, lastEdgeCount + entriesPerEdge())
                return addEdge(from, to, weight, capacity, lastEdgeCount)
            }
        }

        protected fun entriesPerEdge(): Int {
            return 1
        }

        fun addWeightedEdge(from: Int, to: Int, weight: Long): Int {
            return addFlowWeightedEdge(from, to, weight, 0)
        }

        fun addSimpleEdge(from: Int, to: Int): Int {
            return addWeightedEdge(from, to, 0)
        }

        fun firstOutbound(vertex: Int): Int {
            var id = firstOutbound[vertex]
            while (id != -1 && isRemoved(id)) {
                id = nextOutbound[id]
            }
            return id
        }

        fun nextOutbound(id: Int): Int {
            var id = id
            id = nextOutbound[id]
            while (id != -1 && isRemoved(id)) {
                id = nextOutbound[id]
            }
            return id
        }

        fun destination(id: Int): Int {
            return to[id]
        }

        fun flag(id: Int, bit: Int): Boolean {
            return flags[id] shr bit and 1 != 0
        }

        fun isRemoved(id: Int): Boolean {
            return flag(id, REMOVED_BIT)
        }

        protected fun ensureEdgeCapacity(size: Int) {
            /*if (from.length < size) {
            int newSize = Math.max(size, 2 * from.length);
            if (edgesInit) {
                edges = resize(edges, newSize);
            }
            from = resize(from, newSize);
            to = resize(to, newSize);
            nextOutbound = resize(nextOutbound, newSize);
            if (inboundInit) {
                nextInbound = resize(nextInbound, newSize);
            }
            if (weightInit) {
                weight = resize(weight, newSize);
            }
            if (capacityInit) {
                capacity = resize(capacity, newSize);
            }
            if (capacityInit) {
                reverseEdge = resize(reverseEdge, newSize);
            }
            flags = resize(flags, newSize);
        }*/
        }

        protected inner class GraphEdge(protected var id: Int) : Edge

        companion object {
            protected val EMPTY_INT = IntArray(0)
            protected val EMPTY_LONG = LongArray(0)
            protected val EMPTY_EDGE = arrayOfNulls<Edge>(0)
            val REMOVED_BIT = 0
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

            val pair = o as IntIntPair?

            return first == pair!!.first && second == pair.second
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

    internal object MiscUtils {
        fun decreaseByOne(vararg arrays: IntArray) {
            for (array in arrays) {
                for (i in array.indices) {
                    array[i]--
                }
            }
        }

    }

    internal object ArrayUtils {
        fun fill(array: Array<LongArray>, value: Long) {
            for (row in array) {
                Arrays.fill(row, value)
            }
        }

        fun fill(array: Array<IntArray>, value: Int) {
            for (row in array) {
                Arrays.fill(row, value)
            }
        }

        fun fill(array: Array<Array<IntArray>>, value: Int) {
            for (subArray in array) {
                fill(subArray, value)
            }
        }

    }

    internal interface Edge

    internal class OutputWriter {
        private val writer: PrintWriter

        constructor(outputStream: OutputStream) {
            writer = PrintWriter(BufferedWriter(OutputStreamWriter(outputStream)))
        }

        constructor(writer: Writer) {
            this.writer = PrintWriter(writer)
        }

        fun close() {
            writer.close()
        }

        fun printLine(i: Long) {
            writer.println(i)
        }

    }
}