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

    var lo = ArrayList<Int>()
    var hi = ArrayList<Int>()
    for (i in 0 until 200001) {
        lo.add(1000000)
        hi.add(-1000000)
    }
    var l = 0
    var r = 0
    var Q = readInt()
    for (i in 0 until Q) {
        var type = read()
        var X = readInt()
        if (type == "L") {
            lo[X] = Math.min(lo[X], l)
            hi[X] = Math.max(hi[X], l)
            l--
            if (r == 0) r++
        } else if (type == "R") {
            lo[X] = Math.min(lo[X], r)
            hi[X] = Math.max(hi[X], r)
            r++
            if (l == 0) l--
        } else {

            println(Math.min(r-hi[X]-1, lo[X]-l-1))
        }
    }

}