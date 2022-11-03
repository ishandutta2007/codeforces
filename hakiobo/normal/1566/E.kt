import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val cons = Array(n) { mutableListOf<Int>() }
        val parent = IntArray(n) { -1 }
        val isBud = BooleanArray(n)
        repeat(n - 1) {
            val u = br.readInt() - 1
            val v = br.readInt() - 1
            cons[u].add(v)
            cons[v].add(u)
        }
        var ans = 1
        fun dfs(node: Int) {
            var leafCount = 0
            for (child in cons[node]) {
                if (child != parent[node]) {
                    parent[child] = node
                    dfs(child)
                    if (!isBud[child]) {
                        isBud[node] = true
                        leafCount++
                    }
                }
            }
            if (isBud[node]) {
                ans += leafCount - 1
            }
        }
        dfs(0)
        sb.appendLine(ans)

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