import java.io.BufferedReader

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
        if (n == 1) {
            bw.appendLine("0")
        } else {
            var root = 0
            for (i in 1 until n) {
                if (cons[i].size > cons[root].size) {
                    root = i
                }
            }
            if (cons[root].size <= 2) {
                bw.appendLine("1")
            } else {
                var ans = 0
                fun r(node: Int, parent: Int): Boolean {
                    if (cons[node].size == 1) return true
                    var childLeafCount = 0
                    for (adj in cons[node]) {
                        if (adj != parent) {
                            if (r(adj, node)) {
                                childLeafCount++
                            }
                        }
                    }
                    return when (childLeafCount) {
                        0 -> false
                        1 -> cons[node].size == 2
                        else -> {
                            ans += childLeafCount - 1
                            false
                        }
                    }
                }
                r(root, -1)
                bw.appendLine("$ans")
            }
        }
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