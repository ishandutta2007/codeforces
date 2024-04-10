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
    var (N, M, Q) = readInts(3)
    var A = Array(N) {CharArray(M) }
    for (i in 0 until N) {
        A[i] = read().toCharArray()
    }
    var p = Array(N*M+1){IntArray(26){-1} }
    var w = IntArray(N*M+1){0}
    var quer = Array(Q) {CharArray(M)}
    for (i in 0 until Q) {
        quer[i] = read().toCharArray()
    }
    var qpos = IntArray(Q){0}
    var qans = IntArray(Q){-1}
    var nxt = 1

    for (i in 0 until N) {
        var curp  = 0
        for (j in 0 until M) {
            var cur = A[i][j] - 'a'
            if (p[curp][cur] == -1) {
                p[curp][cur] = nxt
                nxt++
            }
            curp = p[curp][cur]
        }
    }
    for (i in N*M downTo 0) {
        w[i] = 1
        for (j in 0 until 26) {

            if (p[i][j] != -1) w[i] += w[p[i][j]]
        }
    }
    fun merge(a : Int, b : Int) {
        w[a] = 1
        for (i in 0 until 26) {
            if (p[a][i] == -1) {
                p[a][i] = p[b][i]
            } else if (p[b][i] != -1) {
                merge(p[a][i], p[b][i])
            }
            if (p[a][i] != -1) w[a] += p[a][i]
        }

    }
    var rt = 0
    for (x in 0 until M) {
        for (i in 0 until Q) {
            if (qpos[i] == x) {
                var cur = rt
                for (j in x until M) {
                    var ch = quer[i][j] - 'a'
                    if (p[cur][ch] == -1) {
                        break
                    }
                    cur = p[cur][ch]
                    qpos[i] = j+1
                }
                qans[i]++
            }

        }
        var cur = -1
        for (i in 0 until 26) {
            if (p[rt][i] != -1) {
                if (cur == -1) {
                    cur = p[rt][i]
                } else {
                    if (w[cur] < w[p[rt][i]]) {
                        merge(p[rt][i], cur)
                        cur = p[rt][i]
                    } else {
                        merge(cur, p[rt][i])
                    }
                }
            }
        }
        if (cur != -1) rt = cur
    }

    for (i in 0 until Q) {
        if (qpos[i] == M) {
            print(qans[i])
        } else {
            print(-1)
        }
        print('\n')
    }

}