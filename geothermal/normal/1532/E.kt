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
    var A = readLongArray(N)
    var sum = 0L
    var max = 0L
    var maxInd = 0
    for (i in 0 until N) {
        sum += A[i]
        if (max < A[i]) {
            max = A[i]
            maxInd = i
        }
    }
    var res = ArrayList<Int>()
    var secMax = 0L
    for (i in 0 until N) {
        if (i == maxInd) continue
        if (A[i] > secMax) {
            secMax = A[i]
        }
        if (max * 2 == sum - A[i]) {
            res.add(i)
        }
    }
    if (sum - max == secMax * 2) {
        res.add(maxInd)
    }
    println(res.size)
    for (i in 0 until res.size) {
        print((res[i]+1).toString() + ' ')
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