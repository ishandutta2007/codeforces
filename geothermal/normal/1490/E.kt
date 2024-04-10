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

data class Player(val tokens: Long, val index: Int)

fun main(args: Array<String>) {

    var tt = readInt()
    for (qq in 0 until tt) {
        var N = readInt()
        var A = readLongArray(N)
        var B = Array<Player>(N) {i -> Player(A[i], i) }
        B.sortBy {it -> it.tokens}

        var ans = ArrayList<Int>()
        var sum = 0L
        for (i in 0 until N) {
            if (sum < B[i].tokens) {
                ans.clear()
            }
            sum += B[i].tokens
            ans.add(B[i].index)
        }
        ans.sortBy{it -> it }
        println(ans.size)
        for (i in 0 until ans.size) {
            print((ans[i]+1))
            print(" ")
        }
        println()


    }
}