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
    var tt = readInt()
    for (qq in 0 until tt) {
        var N = readInt()
        var A = readIntArray(N)
        var used = BooleanArray(N){false}
        var ans = IntArray(N)
        var cur = 0
        for (it in 0 until N) {
            var best = -1
            var ind = -1
            for (i in 0 until N) {
                if (used[i]) continue
                if (best == -1) {
                    best = A[i]
                    ind = i
                } else if (best > cur && (A[i] > best || A[i] <= cur)) {
                    best = A[i]
                    ind = i
                } else if (best <= cur && (A[i] > best && A[i] <= cur)) {
                    best = A[i]
                    ind = i
                }
            }
            used[ind] = true
            ans[it] = ind+1
            if (best <= cur) {
                cur = 0
            }
            cur++
        }

        for (i in 0 until N) {
            print(ans[i])
            print(" ")
        }
        print('\n')

    }
}