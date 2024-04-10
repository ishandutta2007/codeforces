import java.io.BufferedReader

fun main() {
    fun modPow(n: Long, k: Int, m: Long): Long {
        if (k == 0) {
            return 1L
        }
        var half = modPow(n, k shr 1, m)
        half *= half
        if (k and 1 == 1) {
            half %= m
            half *= n
        }
        return half % m
    }

    val br = System.`in`.bufferedReader()
    val mod = 1_000_000_007L
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
        if (k == 2) {
            sb.appendLine((n * (n - 1)) shr 1)
        } else {
            fun dfs(node: Int, prev: Int, ancestor: Int, dp: Array<IntArray>, depth: Int) {
                dp[ancestor][depth]++
                for (child in cons[node]) {
                    if (child != prev) {
                        dfs(child, node, ancestor, dp, depth + 1)
                    }
                }
            }

            var ans = 0L
            for (root in 0 until n) {
                if (cons[root].size < k) continue
                val dp = Array(n) { IntArray(n) }
                for (child in cons[root]) {
                    dfs(child, root, child, dp, 0)
                }
                for (depth in 0 until n) {
                    val choices = mutableListOf<Int>()
                    for (child in cons[root]) {
                        if (dp[child][depth] != 0) {
                            choices += dp[child][depth]
                        }
                    }
                    if (choices.size < k) break
                    val choiceDp = Array(choices.size + 1) { LongArray(k + 1) }
                    choiceDp[0][0] = 1L
                    for (x in 1..choices.size) {
                        for (y in 0..k) {
                            choiceDp[x][y] += choiceDp[x - 1][y]
                            choiceDp[x][y] %= mod
                        }
                        for (y in 1..k) {
                            choiceDp[x][y] += choiceDp[x - 1][y - 1] * choices[x - 1]
                            choiceDp[x][y] %= mod
                        }
                    }

                    ans += choiceDp.last().last()
                    ans %= mod
                }
            }
            sb.appendLine(ans)
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