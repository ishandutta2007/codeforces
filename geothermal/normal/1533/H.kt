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

data class Pos(var x : Int, var y : Int)

fun solve() {
    var (N, M) = readInts(2)
    var S = readStrings(N)
    var nxt = Array(N) { Array(M) { IntArray(5) { M} } }

    for (i in 0 until N) {
        for (j in M-1 downTo 0) {
            if (j < M-1) {
                for (k in 0 until 5) {
                    nxt[i][j][k] = nxt[i][j+1][k]
                }

            }
            nxt[i][j][S[i][j]-'A'] = j
        }
    }
    var ans = LongArray(6) {0}

    var st = Array<Pos>(N+2) { Pos(0, 0)}
    for (m in 0 until 32) {
        var cnt = 0
        for (i in 0 until 5) {
            if ((m and (1 shl i)) > 0) {
                cnt++
            }
        }
        for (i in 0 until M) {
            st[0] = Pos(-1, -1)
            var sp = 0
            var ca = 0L
            for (j in 0 until N) {
                var res = M
                for (k in 0 until 5) {
                    if ((m and (1 shl k)) > 0) {
                        res = minOf(res, nxt[j][i][k])
                    }
                }
                while (st[sp].y >= res) {
                    var cur = st[sp]
                    sp--
                    ca -= (cur.y - i) * (cur.x - st[sp].x)
                }
                ca += (res - i) * (j - st[sp].x)
                sp++
                st[sp] = Pos(j, res)
                ans[5-cnt] += ca
            }


        }
    }

    var choose = Array(6) { LongArray(6) }
    for (i in 0 until 6) {
        for (j in 0 until 6) {
            if (j == 0) {
                choose[i][j] = 1
            } else if (i < j) {
                choose[i][j] = 0
            } else {
                choose[i][j] = choose[i-1][j] + choose[i-1][j-1]
            }
        }
    }

    for (i in 0 until 6) {
        for (j in 0 until i) {
            ans[i] -= ans[j] * choose[5-j][5-i]
        }
    }



    for (i in 0 until 5) {
        print(ans[i+1])
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