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

fun isSub(A: String, B: String): Boolean {
        for (i in 0 until B.length - A.length + 1) {
            var bad = false
            for (j in 0 until A.length) {
                if (A[j] != B[i+j]) bad = true
            }
            if (!bad) return true
        }
    return false

}
fun main(args: Array<String>) {

    var N = readInt()
    var strs = ArrayList<String>()
    for (i in 0 until 101) {
        strs.add("")
    }
    var cnt = IntArray(101)
    for (i in 0 until N) {
        var S = read()
        if (strs[S.length].equals("")) {
            strs[S.length] = S
        }
        if (strs[S.length] == S) {
            cnt[S.length]++
        } else {
            println("NO")
            return
        }
    }
    var result = ArrayList<String>()
    var lst = ""
    for (i in 1 until 101) {
        if (strs[i] == "") continue
        if (!isSub(lst, strs[i])) {
            println("NO")
            return
        }
        lst = strs[i]
        for (j in 0 until cnt[i]) {
            result.add(strs[i])
        }
    }
    println("YES")
    for (i in 0 until result.size) {
        println(result[i])
    }
}