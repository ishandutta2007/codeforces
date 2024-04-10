import kotlin.Throws
import java.util.Arrays
import java.lang.Math
import java.io.IOException
import java.util.StringTokenizer
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.lang.Exception
import java.lang.IndexOutOfBoundsException
import java.lang.System
import java.util.NoSuchElementException

fun solve() {
    val n = scanInt()
    val m = scanInt()
    val k = scanInt()
    val edges = arrayOfNulls<IntList>(n)
    for (i in 0 until n) {
        edges[i] = IntList()
    }
    for (i in 0 until m) {
        val a = scanInt() - 1
        val b = scanInt() - 1
        edges[a]!!.push(b)
        edges[b]!!.push(a)
    }
    val dist = IntArray(n)
    Arrays.fill(dist, -1)
    dist[0] = 0
    val queue = IntArray(n)
    var queueHead = 0
    var queueTail = 1
    do {
        val cur = queue[queueHead++]
        val e = edges[cur]
        for (i in 0 until e!!.size) {
            val next = e.data[i]
            if (dist[next] < 0) {
                dist[next] = dist[cur] + 1
                queue[queueTail++] = next
            }
        }
    } while (queueHead < queueTail)
    Flow.n = n + m + 2
    Flow.init()
    var pos = n + 2
    for (i in 0 until n) {
        if (dist[i] and 1 == 0) {
            val e = edges[i]
            for (j in 0 until e!!.size) {
                val jj = e.data[j]
                if (dist[jj] == dist[i] + 1) {
                    Flow.addEdge(0, pos, 1, 0)
                    Flow.addEdge(pos, 2 + i, 1, 0)
                    Flow.addEdge(pos, 2 + jj, 1, 0)
                    ++pos
                }
            }
        } else {
            val e = edges[i]
            for (j in 0 until e!!.size) {
                val jj = e.data[j]
                if (dist[jj] == dist[i] + 1) {
                    Flow.addEdge(pos, 1, 1, 0)
                    Flow.addEdge(2 + i, pos, 1, 0)
                    Flow.addEdge(2 + jj, pos, 1, 0)
                    ++pos
                }
            }
        }
    }
    out.println(Math.min(k, Flow.dinic(0, 1)))
}

fun scanInt(): Int {
    return scanString().toInt()
}

fun scanLong(): Long {
    return scanString().toLong()
}

fun scanString(): String {
    var t = tok
    while (t == null || !t.hasMoreTokens()) {
        t = StringTokenizer(inp.readLine())
        tok = t
    }
    return t.nextToken()
}

val inp = BufferedReader(InputStreamReader(System.`in`))
val out = PrintWriter(System.out)
var tok: StringTokenizer? = null
fun main() {
    solve()
    inp.close()
    out.close()
}

internal object Flow {
    var n = 0
    var edgesLen: IntArray? = null
    var edges: Array<IntArray>? = null
    var capsLen = 0
    var caps: IntArray? = null
    fun init() {
        edgesLen = IntArray(n)
        edges = Array(n) { IntArray(6) }
        capsLen = 0
        caps = IntArray(6)
    }

    fun addEdge(from: Int, to: Int, capacity: Int, reverseCapacity: Int): Int {
        val cap = capsLen
        if (caps!!.size == cap) {
            caps = Arrays.copyOf(caps, (cap shl 1) + 2)
        }
        caps!![cap] = capacity
        caps!![cap + 1] = reverseCapacity
        capsLen = cap + 2
        var e1s = edges!![from]
        val e1 = edgesLen!![from]
        if (e1s.size == e1) {
            edges!![from] = Arrays.copyOf(e1s, (e1 shl 1) + 2)
            e1s = edges!![from]
        }
        e1s[e1] = to
        e1s[e1 + 1] = cap
        edgesLen!![from] = e1 + 2
        var e2s = edges!![to]
        val e2 = edgesLen!![to]
        if (e2s.size == e2) {
            edges!![to] = Arrays.copyOf(e2s, (e2 shl 1) + 2)
            e2s = edges!![to]
        }
        e2s[e2] = from
        e2s[e2 + 1] = cap + 1
        edgesLen!![to] = e2 + 2
        return cap
    }

    fun dinic(source: Int, sink: Int): Int {
        val dist = IntArray(n)
        val curEdge = IntArray(n)
        val queue = IntArray(n)
        var flow = 0
        while (true) {
            Arrays.fill(dist, -1)
            dist[source] = 0
            queue[0] = source
            var queueHead = 0
            var queueTail = 1
            do {
                val cur = queue[queueHead++]
                val ndist = dist[cur] + 1
                var i = 0
                val e = edges!![cur]
                val en = edgesLen!![cur]
                while (i < en) {
                    if (caps!![e[i + 1]] == 0) {
                        i += 2
                        continue
                    }
                    val to = e[i]
                    if (dist[to] < 0) {
                        dist[to] = ndist
                        queue[queueTail++] = to
                    }
                    i += 2
                }
            } while (queueHead < queueTail)
            if (dist[sink] < 0) {
                return flow
            }
            Arrays.fill(curEdge, 0)
            var stackSize = 0
            var cur = source
            var eNum = 0
            cur@ while (true) {
                if (cur == sink) {
                    var curFlow = Int.MAX_VALUE
                    for (i in 0 until stackSize) {
                        val c = queue[i]
                        curFlow = Math.min(curFlow, caps!![edges!![c][curEdge[c] + 1]])
                    }
                    for (i in 0 until stackSize) {
                        val c = queue[i]
                        val cap = edges!![c][curEdge[c] + 1]
                        caps!![cap] -= curFlow
                        caps!![cap xor 1] += curFlow
                    }
                    flow += curFlow
                    stackSize = 0
                    cur = source
                    eNum = curEdge[source]
                    continue
                }
                val ndist = stackSize + 1
                val e = edges!![cur]
                val en = edgesLen!![cur]
                while (eNum < en) {
                    val next = e[eNum]
                    if (caps!![e[eNum + 1]] != 0 && dist[next] == ndist) {
                        curEdge[cur] = eNum
                        queue[stackSize++] = cur
                        cur = next
                        eNum = curEdge[cur]
                        continue@cur
                    }
                    eNum += 2
                }
                curEdge[cur] = eNum
                if (stackSize == 0) {
                    break
                }
                cur = queue[--stackSize]
                eNum = curEdge[cur] + 2
            }
        }
    }
}

internal class IntList {
    var data = IntArray(3)
    var size = 0
    val isEmpty: Boolean
        get() = size == 0

    fun size(): Int {
        return size
    }

    operator fun get(index: Int): Int {
        if (index < 0 || index >= size) {
            throw IndexOutOfBoundsException()
        }
        return data[index]
    }

    fun clear() {
        size = 0
    }

    operator fun set(index: Int, value: Int) {
        if (index < 0 || index >= size) {
            throw IndexOutOfBoundsException()
        }
        data[index] = value
    }

    fun expand() {
        if (size >= data.size) {
            data = Arrays.copyOf(data, (data.size shl 1) + 1)
        }
    }

    fun insert(index: Int, value: Int) {
        if (index < 0 || index > size) {
            throw IndexOutOfBoundsException()
        }
        expand()
        System.arraycopy(data, index, data, index + 1, size++ - index)
        data[index] = value
    }

    fun delete(index: Int): Int {
        if (index < 0 || index >= size) {
            throw IndexOutOfBoundsException()
        }
        val value = data[index]
        System.arraycopy(data, index + 1, data, index, --size - index)
        return value
    }

    fun push(value: Int) {
        expand()
        data[size++] = value
    }

    fun pop(): Int {
        if (size == 0) {
            throw NoSuchElementException()
        }
        return data[--size]
    }

    fun unshift(value: Int) {
        expand()
        System.arraycopy(data, 0, data, 1, size++)
        data[0] = value
    }

    fun shift(): Int {
        if (size == 0) {
            throw NoSuchElementException()
        }
        val value = data[0]
        System.arraycopy(data, 1, data, 0, --size)
        return value
    }
}