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
    var S = read()
    var N = S.length
    var zeroes = ArrayList<Int>()
    var ones = ArrayList<Int>()
    var nextZero = IntArray(N) { it -> -1}
    var nextOne = IntArray(N) { it -> -1}

    for (i in 0 until N) {
        if (S[i] == '1') {
            nextOne[i] = ones.size
            ones.add(i)
        } else {
            nextZero[i] = zeroes.size
            zeroes.add(i)
        }
    }

    if (S[N-1] == '1') {
        nextZero[N-1] = zeroes.size
    } else {
        nextOne[N-1] = ones.size
    }
    for (i in N-2 downTo 0) {
        if (S[i] == '1') {
            nextZero[i] = nextZero[i+1]
        } else {
            nextOne[i] = nextOne[i+1]
        }
    }

    for (i in 1 until N+1) {
        var ans = 0
        var p = 0
        while (p < N) {
            var nz = nextZero[p] + i
            var no = nextOne[p] + i
            var ni = N
            if (nz < zeroes.size) ni = zeroes[nz]
            if (no < ones.size) { ni = maxOf(ni, ones[no]) } else ni = N
            /*if (i == 1) {
                println(p.toString() + ' ' + ni.toString())
                println(nz.toString() + ' ' + no.toString())
            }*/
            p = ni
            ans++
        }
        print(ans)
        print(' ')
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