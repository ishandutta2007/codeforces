import java.io.BufferedReader
import java.util.PriorityQueue

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val m = br.readInt()
    val outDegrees = IntArray(n)
    val inDegrees = IntArray(n)
    val froms = IntArray(m)
    val tos = IntArray(m)
    for (i in 0 until m) {
        froms[i] = br.readInt() - 1
        tos[i] = br.readInt() - 1
        outDegrees[froms[i]]++
        inDegrees[tos[i]]++
    }
    val cons = Array(n) { i -> IntArray(outDegrees[i]) }
    val revCons = Array(n) { i -> IntArray(inDegrees[i]) }
    outDegrees.fill(0)
    inDegrees.fill(0)
    for (i in 0 until m) {
        cons[froms[i]][outDegrees[froms[i]]++] = i
        revCons[tos[i]][inDegrees[tos[i]]++] = i
    }
    // outDegrees now functions as count of "bad children"
    val dists = IntArray(n) { Int.MAX_VALUE }
    dists[n - 1] = 0
    val pq = PriorityQueue<Pair<Int, Int>>() { a, b -> a.first.compareTo(b.first) }
    pq += 0 to n - 1
    while (pq.isNotEmpty()) {
        val (dist, node) = pq.poll()
        if (dists[node] == dist) {
            for (edge in revCons[node]) {
                val prev = froms[edge]
                outDegrees[prev]--
                val newDist = outDegrees[prev] + 1 + dist
                if (newDist < dists[prev]) {
                    dists[prev] = newDist
                    pq += newDist to prev
                }
            }
        }
    }
    println(dists.first())

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