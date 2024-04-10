import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val k = br.readInt()
        val cons = Array(n) { mutableListOf<Int>() }
        repeat(n - 1) {
            val u = br.readInt() - 1
            val v = br.readInt() - 1
            cons[u].add(v)
            cons[v].add(u)
        }
        val degrees = IntArray(n) { idx -> cons[idx].size }
        val movesToRemove = IntArray(n)
        val queue = ArrayDeque<Int>()
        for (x in 0 until n) {
            if (degrees[x] <= 1) {
                movesToRemove[x] = 1
                queue.addLast(x)
            }
        }
        while (queue.isNotEmpty()) {
            val node = queue.removeFirst()
            for (adj in cons[node]) {
                if (movesToRemove[adj] == 0) {
                    degrees[adj]--
                    if (degrees[adj] <= 1) {
                        movesToRemove[adj] = movesToRemove[node] + 1
                        queue.addLast(adj)
                    }
                }
            }
        }
        sb.appendLine(movesToRemove.count { it > k })
    }
    println(sb)
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