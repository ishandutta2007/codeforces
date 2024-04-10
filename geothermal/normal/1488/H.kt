import java.io.PrintWriter
import java.util.*
import javax.swing.text.Segment
import kotlin.collections.ArrayList
import kotlin.system.exitProcess

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
    val MOD = 998244353
    for (qq in 0 until tt) {
        var (N, Q) = readInts(2)
        var seg = Array<LongArray>(262144, {it -> LongArray(16)})
        var A = readIntArray(N-1)
        fun combine( p : Int,  l : Int,  r : Int) {
            for (i in 0 until 16) seg[p][i] = 0
            for (a in 0 until 4) {
                for (b in 0 until 4) {
                        for (c in 0 until 4) {
                            seg[p][a*4+c] += seg[l][a*4+b] * seg[r][b*4+c]
                            seg[p][a*4+c] = seg[p][a*4+c] % MOD
                        }
                }
            }
            /*for (i in 0 until 16) {
                println("" + seg[p][i] + " " + seg[l][i] + " " + seg[r][i])

            }
            for (i in 0 until 16) {
                if (seg[p][i] > 1) {
                    println(p)
                    println(l)
                    println(r)
                    exitProcess(0)
                }
            }*/

        }


        var lo = LongArray(16)
        var hi = LongArray(16)
        for (i in 0 until 4) {
            for (j in 0 until 4) {
                if (i < j) {
                    lo[i*4+j] = 1
                } else if (i > j) {
                    hi[i*4+j] = 1
                }
            }
        }
        var loOk = lo.clone()
        var hiOk = hi.clone()
        var id = LongArray(16)
        for (i in 0 until 4) {
            loOk[i*5] = 1
            hiOk[i*5] = 1
            id[i*5] = 1
        }

        seg = Array<LongArray>(262144, {it -> id.clone()})
        //combine(0, 1, 2)
        //return
        fun update(p : Int, nxt : LongArray) {
            var cp = p + 131072
            seg[cp] = nxt.clone()

            while (cp > 1) {
                cp /= 2
                combine(cp, cp*2, cp*2+1)
            }

        }

        fun go(i : Int) {
                if (A[i] == 0) {
                    if (i == N - 2 || A[i + 1] == 0) {
                        update(i, loOk)
                    } else {
                        update(i, lo)
                    }
                } else {
                    if (i != N - 2 && A[i + 1] == 1) {
                        update(i, hiOk)
                    } else {
                        update(i, hi)
                    }
                }
        }



        for (i in 0 until N-1) {
            go(i)
        }



        for (i in 0 until Q) {
            var X = readInt()
            X--
            A[X] = 1-A[X]
            go(X)
            if (X > 0) go(X-1)
            var ans = 0L
            for (j in 0 until 16) ans += seg[1][j]
            println(ans%MOD)

        }




    }
}