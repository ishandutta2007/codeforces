
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
        val outputStream = System.out
        val `in` = InputReader(inputStream)
        val out = OutputWriter(outputStream)
        val solver = TaskE()
        val testCount = Integer.parseInt(`in`.next())
        for (i in 1..testCount) {
            solver.solve(i, `in`, out)
        }
        out.close()
    }

    internal class TaskE {
        fun solve(testNumber: Int, `in`: InputReader, out: OutputWriter) {
            val n = `in`.readInt()
            val k = `in`.readInt()
            val x = IntArray(n - 1)
            val y = IntArray(n - 1)
            `in`.readIntArrays(x, y)
            MiscUtils.decreaseByOne(x, y)
            val graph = BidirectionalGraph.createGraph(n, x, y)
            val deg = IntArray(n)
            for (i in x) {
                deg[i]++
            }
            for (i in y) {
                deg[i]++
            }
            val ends = ArrayUtils.count(deg, 1)
            if (ends < k) {
                out.printLine("No")
                return
            }
            out.printLine("Yes")
            if (k == 1) {
                out.printLine(1)
                out.printLine(1)
                return
            }
            val queue = IntArrayQueue()
            for (i in 0 until n) {
                if (deg[i] == 1) {
                    queue.add(i)
                }
            }
            val inRes = BooleanArray(n)
            Arrays.fill(inRes, true)
            while (queue.size() > k) {
                val cur = queue.poll()
                inRes[cur] = false
                var i = graph.firstOutbound(cur)
                while (i != -1) {
                    val to = graph.destination(i)
                    if (inRes[to] && --deg[to] == 1) {
                        queue.add(to)
                    }
                    i = graph.nextOutbound(i)
                }
            }
            val answer = IntArrayList()
            for (i in 0 until n) {
                if (inRes[i]) {
                    answer.add(i + 1)
                }
            }
            out.printLine(answer.size())
            out.printLine(answer)
        }

    }

    internal interface IntList : IntReversableCollection {
        operator fun get(index: Int): Int

        fun addAt(index: Int, value: Int)

        fun removeAt(index: Int)

        override fun intIterator(): IntIterator {
            return object : IntIterator {
                private var at: Int = 0
                private var removed: Boolean = false

                override val isValid: Boolean
                    get() = !removed && at < size()

                override fun value(): Int {
                    if (removed) {
                        throw IllegalStateException()
                    }
                    return get(at)
                }

                override fun advance(): Boolean {
                    at++
                    removed = false
                    return isValid
                }

                fun remove() {
                    removeAt(at)
                    at--
                    removed = true
                }
            }
        }

        override fun add(value: Int) {
            addAt(size(), value)
        }

    }

    internal class IntArr(private val data: IntArray) : IntAbstractStream(), IntList {

        override fun size(): Int {
            return data.size
        }

        override fun get(at: Int): Int {
            return data[at]
        }

        override fun addAt(index: Int, value: Int) {
            throw UnsupportedOperationException()
        }

        override fun removeAt(index: Int) {
            throw UnsupportedOperationException()
        }

    }

    internal class OutputWriter {
        private val writer: PrintWriter

        constructor(outputStream: OutputStream) {
            writer = PrintWriter(BufferedWriter(OutputStreamWriter(outputStream)))
        }

        constructor(writer: Writer) {
            this.writer = PrintWriter(writer)
        }

        fun print(vararg objects: Any) {
            for (i in objects.indices) {
                if (i != 0) {
                    writer.print(' ')
                }
                writer.print(objects[i])
            }
        }

        fun printLine(vararg objects: Any) {
            print(*objects)
            writer.println()
        }

        fun close() {
            writer.close()
        }

        fun printLine(i: Int) {
            writer.println(i)
        }

    }

    internal interface IntReversableCollection : IntCollection

    internal interface Edge

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

        fun readString(): String {
            var c = read()
            while (isSpaceChar(c)) {
                c = read()
            }
            val res = StringBuilder()
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c)
                }
                c = read()
            } while (!isSpaceChar(c))
            return res.toString()
        }

        fun isSpaceChar(c: Int): Boolean {
            return filter?.isSpaceChar(c) ?: isWhitespace(c)
        }

        operator fun next(): String {
            return readString()
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

    internal class IntArrayQueue : IntQueue {
        private var data = EMPTY
        private var from: Int = 0
        private var to: Int = 0

        @JvmOverloads
        constructor(capacity: Int = 3) {
            data = IntArray(Integer.highestOneBit(capacity) shl 1)
        }

        constructor(array: IntArray) : this(array.size) {
            to = array.size
            System.arraycopy(array, 0, data, 0, to)
        }

        constructor(s: IntStream) {
            addAll(s)
        }

        constructor(c: IntCollection) : this(c.size()) {
            addAll(c)
        }

        override fun size(): Int {
            return to - from and data.size - 1
        }

        override fun add(v: Int) {
            ensureCapacity(size() + 1)
            data[to++] = v
            to = to and data.size - 1
        }

        override fun poll(): Int {
            if (from == to) {
                throw NoSuchElementException()
            }
            val result = data[from++]
            from = from and data.size - 1
            return result
        }

        override fun intIterator(): IntIterator {
            return object : IntIterator {
                private var at = from

                override val isValid: Boolean
                    get() = at != to

                override fun value(): Int {
                    if (at == to) {
                        throw NoSuchElementException()
                    }
                    return data[at]
                }

                override fun advance(): Boolean {
                    if (!isValid) {
                        throw NoSuchElementException()
                    }
                    at++
                    at = at and data.size - 1
                    return isValid
                }

                fun remove() {
                    throw UnsupportedOperationException()
                }
            }
        }

        private fun ensureCapacity(capacity: Int) {
            if (data.size <= capacity) {
                val newData = IntArray(Integer.highestOneBit(capacity) shl 1)
                if (from <= to) {
                    System.arraycopy(data, from, newData, 0, size())
                } else {
                    System.arraycopy(data, from, newData, 0, data.size - from)
                    System.arraycopy(data, 0, newData, data.size - from, to)
                }
                to = size()
                from = 0
                data = newData
            }
        }

        companion object {
            private val EMPTY = IntArray(0)
        }

    }

    internal interface IntIterator {

        val isValid: Boolean
        @Throws(NoSuchElementException::class)
        fun value(): Int

        fun advance(): Boolean

    }

    internal class IntArrayList : IntAbstractStream, IntList {
        private var size: Int = 0
        private var data = EMPTY

        @JvmOverloads
        constructor(capacity: Int = 3) {
            data = IntArray(capacity)
        }

        constructor(c: IntCollection) : this(c.size()) {
            addAll(c)
        }

        constructor(c: IntStream) : this() {
            if (c is IntCollection) {
                ensureCapacity(c.size())
            }
            addAll(c)
        }

        constructor(c: IntArrayList) {
            size = c.size()
            data = c.data.clone()
        }

        constructor(arr: IntArray) {
            size = arr.size
            data = arr.clone()
        }

        override fun size(): Int {
            return size
        }

        override fun get(at: Int): Int {
            if (at >= size) {
                throw IndexOutOfBoundsException("at = $at, size = $size")
            }
            return data[at]
        }

        private fun ensureCapacity(capacity: Int) {
            var capacity = capacity
            if (data.size >= capacity) {
                return
            }
            capacity = Math.max(2 * data.size, capacity)
            data = Arrays.copyOf(data, capacity)
        }

        override fun addAt(index: Int, value: Int) {
            ensureCapacity(size + 1)
            if (index > size || index < 0) {
                throw IndexOutOfBoundsException("at = $index, size = $size")
            }
            if (index != size) {
                System.arraycopy(data, index, data, index + 1, size - index)
            }
            data[index] = value
            size++
        }

        override fun removeAt(index: Int) {
            if (index >= size || index < 0) {
                throw IndexOutOfBoundsException("at = $index, size = $size")
            }
            if (index != size - 1) {
                System.arraycopy(data, index + 1, data, index, size - index - 1)
            }
            size--
        }

        companion object {
            private val EMPTY = IntArray(0)
        }

    }

    internal abstract class IntAbstractStream : IntStream {
        override fun toString(): String {
            val builder = StringBuilder()
            var first = true
            val it = intIterator()
            while (it.isValid) {
                if (first) {
                    first = false
                } else {
                    builder.append(' ')
                }
                builder.append(it.value())
                it.advance()
            }
            return builder.toString()
        }

        override fun equals(o: Any?): Boolean {
            if (o !is IntStream) {
                return false
            }
            val c = o as IntStream?
            val it = intIterator()
            val jt = c!!.intIterator()
            while (it.isValid && jt.isValid) {
                if (it.value() != jt.value()) {
                    return false
                }
                it.advance()
                jt.advance()
            }
            return !it.isValid && !jt.isValid
        }

        override fun hashCode(): Int {
            var result = 0
            val it = intIterator()
            while (it.isValid) {
                result *= 31
                result += it.value()
                it.advance()
            }
            return result
        }

    }

    internal object ArrayUtils {
        fun count(array: IntArray, value: Int): Int {
            return IntArr(array).count(value)
        }

    }

    internal interface IntQueue : IntCollection {
        fun poll(): Int

    }

    internal interface IntCollection : IntStream {
        fun size(): Int

        open fun add(value: Int) {
            throw UnsupportedOperationException()
        }

        fun addAll(values: IntStream): IntCollection {
            val it = values.intIterator()
            while (it.isValid) {
                add(it.value())
                it.advance()
            }
            return this
        }

    }

    internal class BidirectionalGraph @JvmOverloads constructor(vertexCount: Int, edgeCapacity: Int = vertexCount) : Graph(vertexCount, 2 * edgeCapacity) {
        var transposedEdge = IntArray(0)

        init {
            transposedEdge = IntArray(2 * edgeCapacity)
        }

        override fun addEdge(fromID: Int, toID: Int, weight: Long, capacity: Long, reverseEdge: Int): Int {
            val lastEdgeCount = edgeCount
            super.addEdge(fromID, toID, weight, capacity, reverseEdge)
            super.addEdge(toID, fromID, weight, capacity, if (reverseEdge == -1) -1 else reverseEdge + 1)
            this.transposedEdge[lastEdgeCount] = lastEdgeCount + 1
            this.transposedEdge[lastEdgeCount + 1] = lastEdgeCount
            return lastEdgeCount
        }

        override fun entriesPerEdge(): Int {
            return 2
        }

        override fun ensureEdgeCapacity(size: Int) {
            if (size > edgeCapacity()) {
                super.ensureEdgeCapacity(size)
                transposedEdge = resize(transposedEdge, edgeCapacity())
            }
        }

        companion object {

            fun createGraph(vertexCount: Int, from: IntArray, to: IntArray): BidirectionalGraph {
                val graph = BidirectionalGraph(vertexCount, from.size)
                for (i in from.indices) {
                    graph.addSimpleEdge(from[i], to[i])
                }
                return graph
            }
        }

    }

    internal interface IntStream : Iterable<Int>, Comparable<IntStream> {
        fun intIterator(): IntIterator

        override fun iterator(): Iterator<Int> {
            return object : Iterator<Int> {
                private val it = intIterator()

                override fun hasNext(): Boolean {
                    return it.isValid
                }

                override fun next(): Int {
                    val result = it.value()
                    it.advance()
                    return result
                }
            }
        }

        override fun compareTo(c: IntStream): Int {
            val it = intIterator()
            val jt = c.intIterator()
            while (it.isValid && jt.isValid) {
                val i = it.value()
                val j = jt.value()
                if (i < j) {
                    return -1
                } else if (i > j) {
                    return 1
                }
                it.advance()
                jt.advance()
            }
            if (it.isValid) {
                return 1
            }
            return if (jt.isValid) {
                -1
            } else 0
        }

        fun count(value: Int): Int {
            var result = 0
            val it = intIterator()
            while (it.isValid) {
                if (it.value() == value) {
                    result++
                }
                it.advance()
            }
            return result
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

    internal open class Graph @JvmOverloads constructor(protected var vertexCount: Int, edgeCapacity: Int = vertexCount) {
        protected var edgeCount: Int = 0
        private var firstOutbound = EMPTY_INT
        private val firstInbound = EMPTY_INT
        private var edges = EMPTY_EDGE
        private var nextInbound = EMPTY_INT
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

        open fun addEdge(fromID: Int, toID: Int, weight: Long, capacity: Long, reverseEdge: Int): Int {
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

        protected open fun entriesPerEdge(): Int {
            return 1
        }

        fun addWeightedEdge(from: Int, to: Int, weight: Long): Int {
            return addFlowWeightedEdge(from, to, weight, 0)
        }

        fun addSimpleEdge(from: Int, to: Int): Int {
            return addWeightedEdge(from, to, 0)
        }

        protected fun edgeCapacity(): Int {
            return from.size
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

        protected open fun ensureEdgeCapacity(size: Int) {
            if (from.size < size) {
                val newSize = Math.max(size, 2 * from.size)
                if (edgesInit) {
                    edges = resize(edges, newSize)
                }
                from = resize(from, newSize)
                to = resize(to, newSize)
                nextOutbound = resize(nextOutbound, newSize)
                if (inboundInit) {
                    nextInbound = resize(nextInbound, newSize)
                }
                if (weightInit) {
                    weight = resize(weight, newSize)
                }
                if (capacityInit) {
                    capacity = resize(capacity, newSize)
                }
                if (capacityInit) {
                    reverseEdge = resize(reverseEdge, newSize)
                }
                flags = resize(flags, newSize)
            }
        }

        protected fun resize(array: IntArray, size: Int): IntArray {
            val newArray = IntArray(size)
            System.arraycopy(array, 0, newArray, 0, array.size)
            return newArray
        }

        private fun resize(array: LongArray, size: Int): LongArray {
            val newArray = LongArray(size)
            System.arraycopy(array, 0, newArray, 0, array.size)
            return newArray
        }

        private fun resize(array: Array<Edge?>, size: Int): Array<Edge?> {
            val newArray = arrayOfNulls<Edge>(size)
            System.arraycopy(array, 0, newArray, 0, array.size)
            return newArray
        }

        protected inner class GraphEdge(protected var id: Int) : Edge

        companion object {
            protected val EMPTY_INT = IntArray(0)
            protected val EMPTY_LONG = LongArray(0)
            protected val EMPTY_EDGE = arrayOfNulls<Edge>(0)
            val REMOVED_BIT = 0
        }

    }
}