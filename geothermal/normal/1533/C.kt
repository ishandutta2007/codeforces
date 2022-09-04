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
    var (N, K) = readInts(2)
    var S = read()
    var sum = 0
    for (i in 0 until N) {
        if (S[i] == '1') sum++
    }
    var A = ArrayList<Int>()
    for (i in 0 until N) {
        A.add(i)
    }
    var p = 0
    var ans = 0
    while (sum > 0) {
        ans++
        if (S[A[p]] == '1') {
            sum--
        }
        A.removeAt(p)
        p += K-1
        if (A.size > 0) p %= A.size
    }
    println(ans)
}

fun main(args: Array<String>) {
    var T = 1
    T = readInt()
    while(T > 0) {
        solve()
        T--
    }

}