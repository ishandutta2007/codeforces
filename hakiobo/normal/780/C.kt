import java.io.BufferedReader
import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val n = br.readInt()
    val cons = Array(n) { mutableListOf<Int>() }
    repeat(n - 1) {
        val u = br.readInt() - 1
        val v = br.readInt() - 1
        cons[u].add(v)
        cons[v].add(u)
    }
    var high = 0
    for (i in 0 until n) {
        high = max(high, cons[i].size)
    }
    bw.appendLine((high + 1).toString())
    val colors = IntArray(n)
    fun color(node: Int, parent: Int) {
        var nextColor = 1
        for(adj in cons[node]) {
            while (nextColor == colors[node] || (parent != -1 && nextColor == colors[parent])) nextColor++
            if(adj != parent) {
                colors[adj] = nextColor++
                color(adj, node)
            }
        }
    }
    colors[0] = 1
    color(0, -1 )
    bw.appendLine(colors.joinToString(" "))
    bw.flush()
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