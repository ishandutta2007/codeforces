import java.io.BufferedReader

private fun BufferedReader.readTree(n: Int): Array<IntArray> {
    val edgesLefts = IntArray(n - 1)
    val edgeRights = IntArray(n - 1)
    val sizes = IntArray(n)
    for (i in 0 until n - 1) {
        val u = readInt() - 1
        val v = readInt() - 1
        edgesLefts[i] = u
        edgeRights[i] = v
        sizes[u]++
        sizes[v]++
    }
    val cons = Array(n) { i -> IntArray(sizes[i]) }
    sizes.fill(0)
    for (i in 0 until n - 1) {
        val u = edgesLefts[i]
        val v = edgeRights[i]
        cons[u][sizes[u]++] = v
        cons[v][sizes[v]++] = u
    }
    return cons
}

private fun addChild(parent: Int, child: Int, letter: Int, trie: Array<IntArray>, uniqueCts: IntArray) {
    if (trie[parent][letter] == -1) {
        uniqueCts[parent] += uniqueCts[child]
        trie[parent][letter] = child
    } else {
        uniqueCts[parent] -= uniqueCts[trie[parent][letter]]
        merge(trie[parent][letter], child, trie, uniqueCts)
        uniqueCts[parent] += uniqueCts[trie[parent][letter]]
    }
}

private fun merge(base: Int, toMergeIn: Int, trie: Array<IntArray>, uniqueCts: IntArray) {
    for (i in 0 until 26) {
        if (trie[toMergeIn][i] != -1) {
            addChild(base, trie[toMergeIn][i], i, trie, uniqueCts)
        }
    }
}

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val c = IntArray(n) { br.readInt() }
    val letters = IntArray(n) { br.read() - 'a'.toInt() }
    val cons = br.readTree(n)
    val trie = Array(n) { IntArray(26) { -1 } }
    val uniqueCts = IntArray(n) { 1 }
    fun dfs(node: Int, parent: Int) {
        for (child in cons[node]) {
            if (child != parent) {
                dfs(child, node)
                addChild(node, child, letters[child], trie, uniqueCts)
            }
        }
        c[node] += uniqueCts[node]
    }

    dfs(0, -1)

    var high = 0
    var ct = 0
    for (i in c) {
        if (i > high) {
            high = i
            ct = 1
        } else if (i == high) {
            ct++
        }
    }
    println(high)
    println(ct)
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