import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val n = br.readInt()
    val m = br.readInt()
    val trie = KH7DTrie(n * m + 1)
    repeat(n) {
        trie.add(br.readLine())
    }
    val q = br.readInt()
    repeat(q) {
        val s = br.readLine()
        var ans = 0
        for (x in 0..m) {
            if (x != 0 && s[x] == s[x - 1]) continue
            if (trie.get(s, x)) ans++
        }
        sb.appendLine(ans)
    }
    print(sb)
}

private class KH7DTrie(n: Int) {
    val trie = Array(n) { IntArray(26) { -1 } }
    var numNodes = 1


    fun get(s: String, idxToSkip: Int): Boolean {
        var curNode = 0
        var curDepth = 0
        var curIdx = 0
        while (curIdx != s.length) {
            if (curIdx == idxToSkip) {
                curIdx++
                continue
            }
            val c = s[curIdx] - 'a'
            if (trie[curNode][c] == -1) {
                return false
            }
            curNode = trie[curNode][c]
            curDepth++
            curIdx++
        }
        return true
    }

    fun add(s: String) {
        var curNode = 0
        var curDepth = 0
        var curIdx = 0
        while (curIdx != s.length) {
            val c = s[curIdx] - 'a'
            if (trie[curNode][c] == -1) {
                trie[curNode][c] = numNodes++
            }
            curNode = trie[curNode][c]
            curDepth++
            curIdx++
        }
    }
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