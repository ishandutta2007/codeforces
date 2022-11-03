import java.io.BufferedReader
import kotlin.math.max
import kotlin.math.min

private fun BufferedReader.readTree(n: Int): Array<IntArray> {
    val edgesLefts = IntArray(n - 1)
    val edgeRights = IntArray(n - 1)
    val sizes = IntArray(n)
    for (i in 0 until n - 1) {
        val u = readInt() - 1
        val v = readInt() - 1
        edgesLefts[i] = u
        edgeRights[i] = v
        sizes[u]++
        sizes[v]++
    }
    val cons = Array(n) { i -> IntArray(sizes[i]) }
    sizes.fill(0)
    for (i in 0 until n - 1) {
        val u = edgesLefts[i]
        val v = edgeRights[i]
        cons[u][sizes[u]++] = v
        cons[v][sizes[v]++] = u
    }
    return cons
}

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val k = br.readInt()
    val cons = br.readTree(n)
    val leafScores = mutableListOf<Int>()
    fun r(node: Int, parent: Int): Int {
        var bestChild = 0
        for (child in cons[node]) {
            if (child != parent) {
                val test = r(child, node)
                if (test > bestChild) {
                    if (bestChild != 0) leafScores += bestChild
                    bestChild = test
                } else {
                    leafScores += test
                }
            }
        }
        return bestChild + 1
    }
    leafScores += r(0, -1)
    var best = Long.MIN_VALUE
    leafScores.sortDescending()
    var red = 0L
    var white = 0L
    var colorable = n.toLong()
    val goalBlue = n.toLong() shr 1
    for (i in 0 until min(k, leafScores.size)) {
        red++
        white += leafScores[i] - 1
        colorable -= leafScores[i]
        val blue = min(colorable, goalBlue)
        val score = red * (n - red) - blue * (n - blue)
        best = max(score, best)
    }
    if (k > leafScores.size) {
        val redH = max(min(k.toLong(), goalBlue), leafScores.size.toLong())
        best = max(best, redH * (n - redH))
    }
    println(best)
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