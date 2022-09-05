import java.io.PrintWriter
import java.util.*

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

fun main(args: Array<String>) {
    var (N, M) = readInts(2)
    var K = readLong()
    var A = readLongArray(N)
    var B = readLongArray(M)
    var C = Array(N) {LongArray(M)}
    for (i in 0 until N) {
        C[i] = readLongArray(M)
    }

    var vals = ArrayList<Long>()
    var costs = ArrayList<Long>()
    vals.add(C[0][0])
    costs.add(0L)
    var a = 1
    var b = 1
    while (a < N || b < M) {
        var na = Long.MAX_VALUE
        var nb = Long.MAX_VALUE
        if (a < N) {
            na = A[a]
        }
        if (b < M) {
            nb = B[b]
        }
        if (na < nb) {
            var best = 0L
            for (i in 0 until b) {
                best = maxOf(best, C[a][i])
            }
            if (best > vals.get(vals.size-1)) {
                vals.add(best)
                costs.add(A[a])
            }
            a++
        } else {
            var best = 0L
            for (i in 0 until a) {
                best = maxOf(best, C[i][b])
            }
            if (best > vals.get(vals.size-1)) {
                vals.add(best)
                costs.add(B[b])
            }
            b++
        }
    }
    vals.add(0)
    costs.add(maxOf(A[N-1], B[M-1]))
    var ans = Long.MAX_VALUE
    for (it in 0 until vals.size-1) {
        var p = 1L
        var sco = 0L
        var mov = 0L
        for (i in 0 until vals.size) {
            if (sco < costs[i]) {
                var cnt = (costs[i] - sco + p-1) / p
                sco += p * cnt
                mov += cnt
            }
            var cur = vals[i]
            if (it == i) cur += K
            p = maxOf(p, cur)
        }
        ans = minOf(ans, mov)
    }
    println(ans)
}