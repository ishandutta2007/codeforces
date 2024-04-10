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
    var (N, M, D) = readInts(3)
    var A = readIntArray(M)
    var cur = D
    for (i in 0 until M) {
        cur += A[i] - 1
        cur += D
    }
    println(if (cur > N) "YES" else "NO")
    if (cur <= N) return
    var remLength = 0
    for (i in 0 until M) remLength += A[i]
    cur = 0
    var ans = IntArray(N){0}
    for (i in 0 until M) {
        if (cur + D + remLength > N) {
            cur = N - remLength
        } else {
            cur += D - 1
        }
        remLength -= A[i]
        for (j in 0 until A[i]) {
            ans[cur] = i+1
            cur++
        }
    }
    for (i in 0 until N) {
        print(ans[i].toString())
        print(" ")
    }
    print('\n')

}