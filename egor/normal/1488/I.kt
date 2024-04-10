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
        val solver = TaskI()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class TaskI {
        fun solve(testNumber: Int, `in`: InputReader, out: OutputWriter) {
            val n = `in`.readInt()
            val m = `in`.readInt()
            val k = `in`.readInt()
            val x = IntArray(m)
            val y = IntArray(m)
            `in`.readIntArrays(x, y)
            MiscUtils.decreaseByOne(x, y)
            val dfsGraph: Graph = BidirectionalGraph.createGraph(n, x, y)
            val dist = ArrayUtils.createArray(n, -1)
            dist[0] = 0
            val queue = IntArray(n)
            var size = 1
            for (i in 0 until n) {
                val cur = queue[i]
                var j = dfsGraph.firstOutbound(cur)
                while (j != -1) {
                    val to = dfsGraph.destination(j)
                    if (dist[to] == -1) {
                        dist[to] = dist[cur] + 1
                        queue[size++] = to
                    }
                    j = dfsGraph.nextOutbound(j)
                }
            }
            val graph = Graph(n + m + 2, 6 * m)
            for (i in 0 until m) {
                if (dist[x[i]] == dist[y[i]]) {
                    continue
                }
                if (Math.min(dist[x[i]], dist[y[i]]) % 2 == 0) {
                    graph.addFlowEdge(n + m, i, 1)
                    graph.addFlowEdge(i, x[i] + m, 1)
                    graph.addFlowEdge(i, y[i] + m, 1)
                } else {
                    graph.addFlowEdge(i, n + m + 1, 1)
                    graph.addFlowEdge(x[i] + m, i, 1)
                    graph.addFlowEdge(y[i] + m, i, 1)
                }
            }
            out.printLine(Math.min(k.toLong(), MaxFlow.dinic(graph, n + m, n + m + 1)))
        }
    }

    internal open class Graph @JvmOverloads constructor(protected var vertexCount: Int, edgeCapacity: Int = vertexCount) {
        protected var edgeCount = 0
        private var firstOutbound = EMPTY_INT
        private val firstInbound = EMPTY_INT
        private val edges = EMPTY_EDGE
        private val nextInbound = EMPTY_INT
        private var nextOutbound = EMPTY_INT
        private var from = EMPTY_INT
        private var to = EMPTY_INT
        private var weight = EMPTY_LONG
        var capacity: LongArray? = EMPTY_LONG
        private var reverseEdge: IntArray? = EMPTY_INT
        private var flags = EMPTY_INT
        private val edgesInit = false
        private val inboundInit = false
        private var weightInit = false
        private var capacityInit = false
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
            from[edgeCount] = fromID
            to[edgeCount] = toID
            if (capacity != 0L) {
                if (!capacityInit) {
                    capacityInit = true
                    this.capacity = LongArray(from.size)
                    this.reverseEdge = IntArray(from.size)
                    Arrays.fill(this.reverseEdge, 0, edgeCount, -1)
                }
                this.capacity!![edgeCount] = capacity
            }
            if (weight != 0L) {
                if (!weightInit) {
                    weightInit = true
                    this.weight = LongArray(from.size)
                }
                this.weight[edgeCount] = weight
            }
            if (reverseEdge != -1) {
                this.reverseEdge!![edgeCount] = reverseEdge
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
            return if (capacity == 0L) {
                addEdge(from, to, weight, 0, -1)
            } else {
                val lastEdgeCount = edgeCount
                addEdge(to, from, -weight, 0, lastEdgeCount + entriesPerEdge())
                addEdge(from, to, weight, capacity, lastEdgeCount)
            }
        }

        protected open fun entriesPerEdge(): Int {
            return 1
        }

        fun addFlowEdge(from: Int, to: Int, capacity: Long): Int {
            return addFlowWeightedEdge(from, to, 0, capacity)
        }

        fun addWeightedEdge(from: Int, to: Int, weight: Long): Int {
            return addFlowWeightedEdge(from, to, weight, 0)
        }

        fun addSimpleEdge(from: Int, to: Int): Int {
            return addWeightedEdge(from, to, 0)
        }

        fun vertexCount(): Int {
            return vertexCount
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

        fun capacity(id: Int): Long {
            return if (capacity == null) {
                0
            } else capacity!![id]
        }

        fun flow(id: Int): Long {
            return if (reverseEdge == null) {
                0
            } else capacity!![reverseEdge!![id]]
        }

        fun pushFlow(id: Int, flow: Long) {
            if (flow == 0L) {
                return
            }
            if (flow > 0) {
                if (capacity(id) < flow) {
                    throw IllegalArgumentException("Not enough capacity")
                }
            } else {
                if (flow(id) < -flow) {
                    throw IllegalArgumentException("Not enough capacity")
                }
            }
            capacity!![id] -= flow
            capacity!![reverseEdge!![id]] += flow
        }

        fun flag(id: Int, bit: Int): Boolean {
            return flags[id] shr bit and 1 != 0
        }

        fun isRemoved(id: Int): Boolean {
            return flag(id, REMOVED_BIT)
        }

        protected open fun ensureEdgeCapacity(size: Int) { /*if (from.length < size) {
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
            const val REMOVED_BIT = 0
        }

        init {
            firstOutbound = IntArray(vertexCount)
            Arrays.fill(firstOutbound, -1)
            from = IntArray(edgeCapacity)
            to = IntArray(edgeCapacity)
            nextOutbound = IntArray(edgeCapacity)
            flags = IntArray(edgeCapacity)
            reverseEdge = IntArray(edgeCapacity)
        }
    }

    internal interface Edge
    internal class BidirectionalGraph @JvmOverloads constructor(vertexCount: Int, edgeCapacity: Int = vertexCount) : Graph(vertexCount, 2 * edgeCapacity) {
        var transposedEdge = IntArray(0)
        override fun addEdge(fromID: Int, toID: Int, weight: Long, capacity: Long, reverseEdge: Int): Int {
            val lastEdgeCount = edgeCount
            super.addEdge(fromID, toID, weight, capacity, reverseEdge)
            super.addEdge(toID, fromID, weight, capacity, if (reverseEdge == -1) -1 else reverseEdge + 1)
            transposedEdge[lastEdgeCount] = lastEdgeCount + 1
            transposedEdge[lastEdgeCount + 1] = lastEdgeCount
            return lastEdgeCount
        }

        override fun entriesPerEdge(): Int {
            return 2
        }

        override fun ensureEdgeCapacity(size: Int) { //        if (size > edgeCapacity()) {
//            super.ensureEdgeCapacity(size);
//            transposedEdge = resize(transposedEdge, edgeCapacity());
//        }
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

        init {
            transposedEdge = IntArray(2 * edgeCapacity)
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

    internal class MaxFlow(private val graph: Graph, private val source: Int, private val destination: Int) {
        private val queue: IntArray
        var pos = 0
        var size = 0
        private val distance: IntArray
        private val nextEdge: IntArray
        fun dinic(): Long {
            var totalFlow: Long = 0
            while (true) {
                edgeDistances()
                if (distance[destination] == -1) {
                    break
                }
                Arrays.fill(nextEdge, -2)
                totalFlow += dinicImpl(source, Long.MAX_VALUE)
            }
            return totalFlow
        }

        private fun edgeDistances() {
            Arrays.fill(distance, -1)
            distance[source] = 0
            size = 0
            pos = size
            queue[size++] = source
            while (pos != size) {
                val current = queue[pos++]
                var id = graph.firstOutbound(current)
                while (id != -1) {
                    if (graph.capacity(id) != 0L) {
                        val next = graph.destination(id)
                        if (distance[next] == -1) {
                            distance[next] = distance[current] + 1
                            queue[size++] = next
                        }
                    }
                    id = graph.nextOutbound(id)
                }
            }
        }

        private fun dinicImpl(source: Int, flow: Long): Long {
            var flow = flow
            if (source == destination) {
                return flow
            }
            if (flow == 0L || distance[source] == distance[destination]) {
                return 0
            }
            var id = nextEdge[source]
            if (id == -2) {
                id = graph.firstOutbound(source)
                nextEdge[source] = id
            }
            var totalPushed: Long = 0
            while (id != -1) {
                val nextDestinationID = graph.destination(id)
                if (graph.capacity(id) != 0L && distance[nextDestinationID] == distance[source] + 1) {
                    val pushed = dinicImpl(nextDestinationID, Math.min(flow, graph.capacity(id)))
                    if (pushed != 0L) {
                        graph.pushFlow(id, pushed)
                        flow -= pushed
                        totalPushed += pushed
                        if (flow == 0L) {
                            return totalPushed
                        }
                    }
                }
                id = graph.nextOutbound(id)
                nextEdge[source] = id
            }
            return totalPushed
        }

        companion object {
            fun dinic(graph: Graph, source: Int, destination: Int): Long {
                return MaxFlow(graph, source, destination).dinic()
            }
        }

        init {
            val vertexCount = graph.vertexCount()
            queue = IntArray(vertexCount)
            distance = IntArray(vertexCount)
            nextEdge = IntArray(vertexCount)
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

    internal class InputReader(private val stream: InputStream) {
        private val buf = ByteArray(1024)
        private var curChar = 0
        private var numChars = 0
        private val filter: SpaceCharFilter? = null
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

    internal object ArrayUtils {
        fun createArray(count: Int, value: Int): IntArray {
            val array = IntArray(count)
            Arrays.fill(array, value)
            return array
        }
    }
}