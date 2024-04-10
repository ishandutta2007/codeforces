import java.io.BufferedReader
import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val t = br.readInt()
    val qNodes = mutableListOf<Int>()
    fun query(): Pair<Int, Int> {
        if(qNodes.size == 0){
            return Pair(-1, Int.MAX_VALUE)
        }
        println("? %d %s".format(qNodes.size, qNodes.joinToString(" ")))
        qNodes.clear()
        val node = br.readInt()
        val dist = br.readInt()
        return Pair(node - 1, dist)
    }
    repeat(t) {
        val n = br.readInt()
        val cons = Array(n) { mutableListOf<Int>() }
        repeat(n - 1) {
            val u = br.readInt() - 1
            val v = br.readInt() - 1
            cons[u].add(v)
            cons[v].add(u)
        }
        for (x in 1..n) {
            qNodes.add(x)
        }
        val (node, dist) = query()
        val queue: Queue<Int> = ArrayDeque()
        val dists = IntArray(n) { -1 }
        queue += node
        dists[node] = 0
        while (queue.isNotEmpty()) {
            val cur = queue.poll()
            for (adj in cons[cur]) {
                if (dists[adj] == -1) {
                    dists[adj] = dists[cur] + 1
                    queue += adj
                }
            }
        }
        var last = -1
        var high = dist + 1
        var low = ((dist + 1) shr 1)
        var mid = (high + low) shr 1
        while (low != high) {
            for (x in 0 until n) {
                if (dists[x] == mid) {
                    qNodes.add(x + 1)
                }
            }
            val (newNode, newDist) = query()
            if (newDist == dist) {
                last = newNode
                low = mid + 1
            } else {
                high = mid
            }
            mid = (high + low) shr 1
        }
        val dists2 = IntArray(n) { -1 }
        queue += last
        dists2[last] = 0
        while (queue.isNotEmpty()) {
            val cur = queue.poll()
            for (adj in cons[cur]) {
                if (dists2[adj] == -1) {
                    dists2[adj] = dists2[cur] + 1
                    queue += adj
                }
            }
        }
        val other = if (dist - dists[last] == 0) {
            node
        } else {
            for (x in 0 until n) {
                if (dists2[x] == dist && dists[x] == dist - dists[last]) {
                    qNodes += x + 1
                }
            }
            query().first
        }

        println("! %d %d".format(last + 1, other + 1))
        br.readLine()
    }
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