import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val m = br.readInt()
        val deltasNeeded = LongArray(n) { br.readInt().toLong() }
        var sum = 0L

        repeat(n) { idx ->
            deltasNeeded[idx] -= br.readInt().toLong()
            sum += deltasNeeded[idx]
        }
        val cons = Array(n) { mutableListOf<Int>() }
        repeat(m) {
            val u = br.readInt() - 1
            val v = br.readInt() - 1
            cons[u].add(v)
            cons[v].add(u)
        }
        val queue = ArrayDeque<Int>()
        val color = IntArray(n) { -1 }
        queue += 0
        color[0] = 0
        var bipartite = true
        var sumA = 0L
        var sumB = 0L
        while (queue.isNotEmpty()) {
            val node = queue.removeFirst()
            if (color[node] == 0) {
                sumA += deltasNeeded[node]
            } else {
                sumB += deltasNeeded[node]
            }
            for (adj in cons[node]) {
                if (color[adj] == -1) {
                    color[adj] = 1 xor color[node]
                    queue += adj
                } else if (color[adj] == color[node]) {
                    bipartite = false
                }
            }
        }
        if (bipartite && sumA == sumB) {
            sb.appendLine("YES")
        } else if (!bipartite && sum and 1L == 0L) {
            sb.appendLine("YES")
        } else {
            sb.appendLine("NO")
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