import java.io.BufferedReader
import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readInt()
    fun comp(a: Pair<Int, Int>, b: Pair<Int, Int>): Int {
        return b.second.compareTo(a.second)
    }
    repeat(numCases) {
        val n = br.readInt()
        val m = br.readInt()
        val cons = Array(n) { mutableListOf<Int>() }
        val rev = Array(n) { mutableListOf<Int>()}
        repeat(m) {
            val start = br.readInt() - 1
            val end = br.readInt() - 1
            cons[start].add(end)
            rev[end].add(start)
        }
        val isClosed = BooleanArray(n)
        val closed = mutableListOf<Int>()
        for (x in 0 until n) {
            if (!isClosed[x]) {
                var good = false
                for(y in rev[x]){
                    if(!isClosed[y]){
                        good = true
                    }
                }
                if(good){
                    for (y in cons[x]) {
                        if (!isClosed[y]) {
                            closed += y + 1
                        }
                        isClosed[y] = true
                    }
                }
            }
        }
        sb.append(closed.size).append('\n').append(closed.joinToString(" ")).append('\n')
    }
    print(sb)
}

private const val SPACE_INT = ' '.toInt()
private const val ZERO_INT = '0'.toInt()
private const val NL_INT = '\n'.toInt()

@Suppress("DuplicatedCode")
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