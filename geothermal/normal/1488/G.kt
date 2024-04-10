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
    for (qq in 0 until tt) {
         var N = readInt()
         var numFacs = IntArray(N+1)
        var vals = ArrayList<Int>()
        for (i in 1 until N+1) {
            for (j in 2*i until N+1 step i) {
                numFacs[j]++
            }
            vals.add(N/i - 1 - numFacs[i])
        }
        vals.sort()
        vals.reverse()
        var cur = 0
        var ans = ArrayList<Int>()
        for (i in 0 until N) {
            ans.add(cur)
            cur += vals[i]
        }
        ans.reverse()
        for (i in 0 until N) {
            print("" + ans[i] + " ")
        }
        println()



    }
}