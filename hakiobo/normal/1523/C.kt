import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val levels = IntArray(n) { br.readInt() }
        val ans = Array(n) { StringBuilder() }
        val help = Array(n) { StringBuilder() }
        val data = IntArray(n)
        fun solve(idx: Int, level: Int): Boolean {
            if (idx == n) return true
            val l = levels[idx]
            if (l == 1) {

                help[level + 1].clear()
                help[level + 1].append(help[level]).append(".1")
                data[level + 1] = 1
                ans[idx].clear()
                ans[idx].append(help[level + 1])
                return solve(idx + 1, level + 1)
            } else {
                var curLevel = level
                while (true) {
                    while (curLevel >= 0 && data[curLevel] + 1 != l) {
                        curLevel--
                    }
                    if (curLevel < 0) return false
                    help[curLevel].clear()
                    if (curLevel == 0) {
                        help[curLevel].append(l)
                    } else {
                        help[curLevel].append(help[curLevel - 1]).append(".").append(l)
                    }
                    data[curLevel]++
                    ans[idx].clear()
                    ans[idx].append(help[curLevel])
                    val res = solve(idx + 1, curLevel)
                    if (res) return true
                    data[curLevel] = l - 1
                    curLevel--
                }
            }
        }
        ans[0].append("1")
        help[0].append("1")
        data[0] = 1
        solve(1, 0)
        sb.appendLine(ans.joinToString("\n"))
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