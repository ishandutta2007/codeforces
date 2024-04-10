import javafx.scene.layout.Priority
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
    var (N, X, K) = readInts(3)
    var A = readLongArray(N)
    var lo = 0L
    var hi = 10000000000
    while (lo < hi) {
        var bs = (lo+hi)/2
        var cur = 0
        var cnt = 0

        while (cur < N) {
            var q = PriorityQueue<Long>()
            var nxt = minOf(cur+K, N)
            var sum = 0L
            for (i in cur until nxt) {
                sum += A[i]
                q.add(-1*A[i])
            }
            while (sum > bs) {

                sum += q.poll()
                if (nxt < N) {
                    q.add(-1*A[nxt])
                    sum += A[nxt]
                    nxt++
                }
                cnt++
            }
            cur = nxt
        }

        if (cnt <= X) {
            hi = bs
        } else {
            lo = bs+1
        }
    }

    println(lo)

}