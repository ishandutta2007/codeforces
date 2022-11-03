import java.io.BufferedReader
import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val m = br.readInt()
        val thisSb = StringBuilder()
        val directed = Array(n) { mutableListOf<Int>() }
        val undirected = Array(n) { mutableListOf<Int>() }
        val cts = IntArray(n)
        repeat(m) {
            val color = br.readInt()
            val x = br.readInt() - 1
            val y = br.readInt() - 1
            if (color == 0) {
                undirected[x].add(y)
                undirected[y].add(x)
            } else {
                directed[x].add(y)
                cts[y]++
            }
        }
        val queue: Queue<Int> = ArrayDeque()
        val processed = BooleanArray(n)
        var numProcessed = 0
        for (x in 0 until n) {
            if (cts[x] == 0) {
                queue += x
            }
        }
        while (queue.isNotEmpty()) {
            val cur = queue.poll()
            for (adj in directed[cur]) {
                thisSb.append(cur + 1).append(' ').append(adj + 1).append('\n')
                cts[adj]--
                if (cts[adj] == 0) {
                    queue += adj
                }
            }
            for (adj in undirected[cur]) {
                if (!processed[adj]) {
                    thisSb.append(cur + 1).append(' ').append(adj + 1).append('\n')
                }
            }
            processed[cur] = true
            numProcessed++
        }
        if(numProcessed == n){
            sb.append("YES\n").append(thisSb)
        } else {
            sb.append("NO\n")
        }
    }
    print(sb)
}

private const val SPACE_INT = ' '.toInt()
private const val ZERO_INT = '0'.toInt()
private const val NL_INT = '\n'.toInt()

private fun BufferedReader.readInt(): Int {
    var ret = read()
    while (ret <= SPACE_INT) {
        ret = read()
    }
    val neg = ret == '-'.toInt()
    if (neg) {
        ret = read()
    }
    ret -= ZERO_INT
    var read = read()
    while (read >= ZERO_INT) {
        ret *= 10
        ret += read - ZERO_INT
        read = read()
    }

    while (read <= SPACE_INT && read != -1 && read != NL_INT) {
        mark(1)
        read = read()
    }
    if (read > SPACE_INT) {
        reset()
    }
    return if (neg) -ret else ret
}