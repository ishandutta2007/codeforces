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
         var N = readInt()
         var A = readIntArray(N)
         var lst = IntArray(N+1, {it -> -1})
         var dp = TreeMap<Int, Int>()
         dp[-1] = N
        dp[N] = 0
        for (i in 0 until N) {

            if (lst[A[i]] != -1) {
                var K = dp[(dp.higherKey(lst[A[i]]) ?: 0)]
                dp[lst[A[i]]] = K!! + 2
                while (dp[(dp.lowerKey(lst[A[i]]) ?: 0)] != null && dp[(dp.lowerKey(lst[A[i]]) ?: 0)]!! < K!!+2) {
                    dp.remove((dp.lowerKey(lst[A[i]]) ?: 0))
                }
            }
            dp[i] = 1
            lst[A[i]] = i
        }

        println(dp[dp.higherKey(-1)?:0])


    }
}