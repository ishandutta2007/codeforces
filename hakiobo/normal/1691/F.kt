import java.io.BufferedReader

private fun BufferedReader.readTree(n: Int): Array<IntArray> {
    val edgesLefts = IntArray(n - 1)
    val edgeRights = IntArray(n - 1)
    val sizes = IntArray(n)
    for (i in 0 until n - 1) {
        val (u, v) = readLine().split(" ").map { it.toInt() - 1 }
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

private fun modPow(n: Long, k: Long, m: Long): Long {
    if (k == 0L) {
        return 1L
    }
    var half = modPow(n, k shr 1, m)
    half *= half
    if (k and 1L == 1L) {
        half %= m
        half *= n
    }
    return half % m
}


fun main() {
    val mod = 1_000_000_007L
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val n = br.readInt()
    val k = br.readInt()
    val tree = br.readTree(n)
    val subtreeSizes = IntArray(n)

    val factorials = LongArray(n + 1)
    factorials[0] = 1L
    for (i in 1..n) {
        factorials[i] = (i * factorials[i - 1]) % mod
    }

    val invFacts = LongArray(n + 1)
    invFacts[n] = modPow(factorials[n], mod - 2, mod)
    for (i in n downTo 1) {
        invFacts[i - 1] = (i * invFacts[i]) % mod
    }
    fun choose(nC: Int, kC: Int): Long {
        if (kC > nC) return 0L
        return (factorials[nC] * ((invFacts[kC] * invFacts[nC - kC]) % mod)) % mod
    }

    var ans = 0L

    fun r(node: Int, parent: Int) {
        var subtreeSize = 1
        var excludedTimes = 0L
        for (child in tree[node]) {
            if (child != parent) {
                r(child, node)
                subtreeSize += subtreeSizes[child]
                excludedTimes += choose(subtreeSizes[child], k)
            }
        }
        excludedTimes += choose(n - subtreeSize, k)
        excludedTimes %= mod


        ans += run {
            val numTrees = choose(subtreeSize, k) - (excludedTimes - choose(n - subtreeSize, k)) + mod
            val numRoots = n - subtreeSize
            val treeSize = subtreeSize
            val totalTree = (numTrees * numRoots) % mod
            totalTree * treeSize
        }
        ans %= mod
        for (child in tree[node]) {
            if (child != parent) {
                ans += run {
                    val numTrees =
                        choose(n - subtreeSizes[child], k) - (excludedTimes - choose(subtreeSizes[child], k)) + mod
                    val numRoots = subtreeSizes[child]
                    val treeSize = n - subtreeSizes[child]
                    val totalTree = (numTrees * numRoots) % mod
                    totalTree * treeSize
                }

                ans %= mod
            }
        }

        ans += n * (choose(n, k) - excludedTimes + mod)
        ans %= mod

        subtreeSizes[node] = subtreeSize
    }
    r(0, -1)
    bw.appendLine(ans.toString())
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