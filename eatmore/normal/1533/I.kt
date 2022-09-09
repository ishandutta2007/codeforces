import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

fun sortBy(a: IntArray, n: Int, v: IntArray) {
    if (n == 0) {
        return
    }
    for (i in 1 until n) {
        var j = i
        val ca = a[i]
        val cv = v[ca]
        do {
            val nj = j - 1 shr 1
            val na = a[nj]
            if (cv <= v[na]) {
                break
            }
            a[j] = na
            j = nj
        } while (j != 0)
        a[j] = ca
    }
    var ca = a[0]
    for (i in n - 1 downTo 1) {
        var j = 0
        while ((j shl 1) + 2 + Int.MIN_VALUE < i + Int.MIN_VALUE) {
            j = j shl 1
            j += if (v[a[j + 2]] > v[a[j + 1]]) 2 else 1
        }
        if ((j shl 1) + 2 == i) {
            j = (j shl 1) + 1
        }
        var na = a[i]
        a[i] = ca
        ca = na
        val cv = v[ca]
        while (j != 0 && v[a[j]] < cv) {
            j = j - 1 shr 1
        }
        while (j != 0) {
            na = a[j]
            a[j] = ca
            ca = na
            j = j - 1 shr 1
        }
    }
    a[0] = ca
}

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

fun fordFulkerson(source: Int, sink: Int): Int {
    val seen = BooleanArray(n)
    return fordFulkersonDfs(seen, sink, source, 1)
}

fun fordFulkersonDfs(seen: BooleanArray, sink: Int, cur: Int, flow: Int): Int {
    if (seen[cur]) {
        return 0
    }
    if (cur == sink) {
        return flow
    }
    seen[cur] = true
    var i = 0
    val e = edges!![cur]
    val en = edgesLen!![cur]
    while (i < en) {
        val cap = e[i + 1]
        if (caps!![cap] == 0) {
            i += 2
            continue
        }
        val curFlow = fordFulkersonDfs(seen, sink, e[i], Math.min(flow, caps!![cap]))
        if (curFlow != 0) {
            caps!![cap] -= curFlow
            caps!![cap xor 1] += curFlow
            return curFlow
        }
        i += 2
    }
    return 0
}

fun solve() {
    val n1 = scanInt()
    val n2 = scanInt()
    val m = scanInt()
    n = n1 + n2 + 1
    init()
    val k = IntArray(n1)
    val idx = IntArray(n1)
    for (i in 0 until n1) {
        k[i] = scanInt()
        idx[i] = i
    }
    sortBy(idx, n1, k)
    val cnt = IntArray(n2)
    for (i in 0 until m) {
        val a = scanInt() - 1
        val b = scanInt() - 1
        addEdge(a, n1 + b, 1, 0)
        ++cnt[b]
    }
    for (i in 0 until n2) {
        addEdge(n1 + i, n1 + n2, cnt[i] - 1, 0)
    }
    var ans = 0
    for (i in n1 - 1 downTo 0) {
        if (fordFulkerson(idx[i], n1 + n2) == 0) {
            ans += k[idx[i]]
        }
    }
    out.print(ans)
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