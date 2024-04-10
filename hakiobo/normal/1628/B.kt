import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()

    repeat(t) {
        val n = br.readInt()
        val scenes = Array(n) { br.readLine() }
        val trie = PeculiarTrie(35153)
        var isGood = false

        for (s in scenes) {
            trie.add(s)
            trie.add(s, s.lastIndex, false)
            isGood = isGood || trie.check(s) || trie.check(s, 1, false)
        }

        if (isGood) sb.appendLine("YES") else sb.appendLine("NO")
    }
    println(sb)
}


private class PeculiarTrie(n: Int) {
    val trie = Array(n) { IntArray(26) { -1 } }
    val isWord = BooleanArray(n)
    val isReal = BooleanArray(n)

    var numNodes = 1

    fun add(s: String, endIdx: Int = s.length, real: Boolean = true) {
        var curNode = 0
        var curIdx = 0
        while (curIdx != endIdx) {
            val c = s[curIdx] - 'a'
            if (trie[curNode][c] == -1) {
                trie[curNode][c] = numNodes++
            }
            curNode = trie[curNode][c]
            curIdx++
        }
        isWord[curNode] = true
        if (real) isReal[curNode] = true
    }

    fun check(s: String, endIdx: Int = 0, real: Boolean = true): Boolean {
        var curNode = 0
        var curIdx = s.lastIndex
        while (curIdx >= endIdx) {
            val c = s[curIdx] - 'a'
            if (trie[curNode][c] == -1) return false
            curNode = trie[curNode][c]
            curIdx--
        }
        return isWord[curNode] && (real || isReal[curNode])
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