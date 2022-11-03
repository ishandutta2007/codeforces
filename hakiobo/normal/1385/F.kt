import java.io.BufferedReader
import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val k = br.readInt()
        val cons = Array(n) { mutableListOf<Int>() }
        val isLeaf = BooleanArray(n)
        val cts = IntArray(n)
        val leafCount = IntArray(n)
        repeat(n - 1) {
            val u = br.readInt() - 1
            val v = br.readInt() - 1
            cons[u].add(v)
            cons[v].add(u)
            cts[u]++
            cts[v]++
        }
        if (k != 1) {
            for (x in 0 until n) {
                if (cts[x] == 1) {
                    isLeaf[x] = true
                    leafCount[cons[x].first()]++
                }
            }
            val queue: Queue<Int> = ArrayDeque()
            for (x in 0 until n) {
                if (leafCount[x] >= k) {
                    queue += x
                }
            }
            var numMoves = 0
            while (queue.isNotEmpty()) {
                val cur = queue.poll()
                val numLeaves = leafCount[cur]
                val moves = numLeaves / k
                leafCount[cur] -= moves * k
                cts[cur] -= moves * k
                numMoves += moves

                if (1 == cts[cur]) {
                    isLeaf[cur] = true
                    for (adj in cons[cur]) {
                        if (!isLeaf[adj]) {
                            leafCount[adj]++
                            if (leafCount[adj] == k) {
                                queue += adj
                            }
                        }
                    }
                }
            }
            sb.append(numMoves).append('\n')
        } else {
            sb.append(n - 1).append('\n')
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