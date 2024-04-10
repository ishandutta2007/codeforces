import com.sun.xml.internal.fastinfoset.util.StringArray
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
    var S = readStrings(2*N-2)
    var longs = ArrayList<String>()
    for (i in 0 until 2*N-2) {
        if (S[i].length == N-1) longs.add(S[i])
    }

    for (iter in 0 until 2) {
        var usedP = BooleanArray(N) { i -> false}
        var usedS = BooleanArray(N) { i -> false}
        var res = CharArray(2*N-2)
        var check = CharArray(N)

        for (i in 0 until N-1) {
            check[i] = longs[iter][i]
        }
        check[N-1] = longs[1-iter][N-2]
        var bad = false
        for (i in 0 until 2*N-2) {
            var ok = !usedP[S[i].length]
            for (j in 0 until S[i].length) {
                ok = ok && S[i][j] == check[j]
            }
            if (ok) {
                res[i] = 'P'
                usedP[S[i].length] = true
            } else {
                ok = !usedS[S[i].length]
                for (j in 1..S[i].length) {
                    ok = ok && S[i][S[i].length-j] == check[N-j]
                }
                if (ok) {
                    res[i] = 'S'
                    usedS[S[i].length] = true
                } else {
                    bad = true
                }
            }
        }
        if (!bad) {
            println(String(res))
            return
        }

    }

}

fun main(args: Array<String>) {
    var T = 1
    //T = readInt()
    while(T > 0) {
        solve()
        T--
    }

}