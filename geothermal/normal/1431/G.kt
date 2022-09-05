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
    var (N, K) = readInts(2)
    var A = readIntArray(N)
    A.sort()
    var value = Array(N) {IntArray(N)}
    for (i in 0 until N) {
        for (j in i+1 until N) {
            if ((j-i)%2 == 0) {
                value[i][j] = 0
            } else {
                var dif = j-i+1
                value[i][j] = 0
                for (k in i until i+dif/2) {
                    value[i][j] -= A[k]
                }
                for (k in i+dif/2 until j+1) {
                    value[i][j] += A[k]
                }
            }
        }
    }
    var dp = Array(N+1) {IntArray(K+1) {-200000000} }
    dp[0][0] = 0
    for (i in 0 until N) {
        for (j in 0 until K+1) {
            dp[i+1][j] = maxOf(dp[i+1][j], dp[i][j])
            for (k in 1 until K+1) {
                if (k+j > K) break
                var np = i + k*2
                if (np > N) break
                dp[np][j+k] = maxOf(dp[np][j+k], dp[i][j] + value[i][np-1])
            }
        }
    }
    /*for (i in 0 until N) {
        for (j in 0 until K+1) {
            print(dp[i][j])
            print( " ")
        }
        print('\n')
    }*/
    println(dp[N][K])
}