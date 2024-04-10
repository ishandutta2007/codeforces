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

    var tt = 1
    tt = readInt()
    for (qq in 0 until tt) {
        var (N, X, Y) = readInts(3)
        var lo = 0
        var hi = N
        if (X > Y) {
            var Z = X
            X = Y
            Y = Z
        }
        X--
        Y--
        while (lo < hi) {
            var mid = (lo+hi)/2
            var ok = false
            if (mid >= X && mid >= N-1-Y) {
                var cnt = 0
                cnt += maxOf(mid-2*X, (mid-X)/2)
                cnt += maxOf(mid-2*(N-1-Y), (mid-(N-Y-1))/2)
                if (Y == X || cnt >= Y - X - 1) {
                    ok = true
                }
            }
            if (ok) {
                hi = mid
            } else {
                lo = mid+1
            }

        }
        println(lo)
    }
}