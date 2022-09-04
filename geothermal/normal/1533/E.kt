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

fun solve() {
    var N = readInt()
    var A = readIntArray(N)
    var B = readIntArray(N+1)
    A.sort()
    B.sort()
    var diffBefore = IntArray(N+1)
    var diffAfter = IntArray(N+1)
    diffBefore[0] = -1000000001
    for (i in 1 until N+1) {
        diffBefore[i] = maxOf(diffBefore[i-1], B[i-1] - A[i-1])
    }
    diffAfter[N] = -1000000001
    for (i in N-1 downTo 0) {
        diffAfter[i] = maxOf(diffAfter[i+1], B[i+1] - A[i])
    }

    var M = readInt()
    for (i in 0 until M) {
        var C = readInt()
        var lo = 0
        var hi = N
        while (lo < hi) {
            var mid = (lo+hi)/2
            if (A[mid] <= C) {
                lo = mid+1
            } else {
                hi = mid
            }
        }
        print(maxOf(maxOf(diffBefore[lo], diffAfter[lo]), B[lo] - C))
        print(' ')

    }
    println()
}

fun main(args: Array<String>) {
    var T = 1
    //T = readInt()
    while(T > 0) {
        solve()
        T--
    }

}