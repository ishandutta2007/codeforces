import java.io.BufferedReader
import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val cons = Array(n) { mutableListOf<Int>() }
        repeat(n - 1) {
            val u = br.readInt() - 1
            val v = br.readInt() - 1
            cons[u].add(v)
            cons[v].add(u)
        }
        val subTreeSize = IntArray(n)
        val scoreIfNotDeleting = IntArray(n)
        fun r(node: Int, parent: Int) {
            subTreeSize[node] = 1
            var deleteSum = 0
            var numChildren = 0
            for (child in cons[node]) {
                if (child != parent) {
                    numChildren++
                    r(child, node)
                    subTreeSize[node] += subTreeSize[child]
                    deleteSum += subTreeSize[child] - 1
                }
            }
            if (numChildren == 1) {
                scoreIfNotDeleting[node] = deleteSum
            }
            for (child in cons[node]) {
                if (child != parent) {
                    scoreIfNotDeleting[node] =
                        max(scoreIfNotDeleting[node], scoreIfNotDeleting[child] + deleteSum - subTreeSize[child] + 1)
                }
            }
        }
        r(0, -1)
        bw.appendLine(scoreIfNotDeleting[0].toString())

    }
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