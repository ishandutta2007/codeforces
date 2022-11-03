import java.io.BufferedReader

private const val LIMIT = 200_000

fun main() {

    fun modPow(n: Long, k: Long, m: Long): Long {
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

    val br = System.`in`.bufferedReader()
    val mod = 998_244_353L
    val initN = br.readInt()
    var n = initN
    val m = br.readInt()
    val facts = LongArray(LIMIT + 1)
    val invFacts = LongArray(LIMIT + 1)
    val regInv = LongArray(LIMIT + 1)
    facts[0] = 1L
    for (x in 1..LIMIT) {
        facts[x] = (facts[x - 1] * x) % mod
        regInv[x] = modPow(x.toLong(), mod - 2, mod)
    }
    invFacts[LIMIT] = modPow(facts[LIMIT], mod - 2, mod)
    for (x in LIMIT downTo 1) {
        invFacts[x - 1] = (invFacts[x] * x) % mod
    }

    val sCounts = IntArray(LIMIT)
    val fen = CFenwick(LIMIT + 1)

    repeat(n) {
        sCounts[br.readInt() - 1]++
    }
    val t = IntArray(m) { br.readInt() - 1 }
    var ans = 0L
    var ways = facts[n]
    for (i in sCounts.indices) {
        val ct = sCounts[i]
        fen.add(i + 1, ct)
        ways = (ways * invFacts[ct]) % mod
    }

    for (c in t) {
        if (n == 0) break
        //fun math here
        val part = (fen.get(c) * ways) % mod
        ans += (part * regInv[n]) % mod
        if (ans >= mod) ans -= mod


        if (sCounts[c] == 0) break
        ways = (ways * regInv[n]) % mod
        ways = (ways * sCounts[c]--) % mod
        fen.add(c + 1, -1)
        n--
    }
    if (n == 0 && initN < m) {
        ans++
        if (ans >= mod) ans -= mod
    }
    println(ans)
}

private class CFenwick(val size: Int) {
    private val ary = IntArray(size)

    fun add(idx: Int, v: Int) {
        var k = idx + 1
        while (k <= size) {
            ary[k - 1] += v
            k += k and -k
        }
    }

    fun set(idx: Int, v: Int) {
        add(idx, v - get(idx, idx))
    }

    fun get(idx: Int): Int {
        var k = idx + 1
        var r = 0
        while (k > 0) {
            r += ary[k - 1]
            k -= k and -k
        }
        return r
    }

    fun get(a: Int, b: Int): Int {
        return get(b) - get(a - 1)
    }

    //returns the 0 indexed index of the largest prefix sum that does not exceed the given value
    fun prefixSearch(v: Int): Int {
        var idx = 0
        var curSum = 0
        var curBit = Integer.highestOneBit(size)
        while (curBit > 0) {
            if (curBit + idx <= size) {
                if (curSum + ary[curBit + idx - 1] <= v) {
                    curSum += ary[curBit + idx - 1]
                    idx += curBit
                }
            }
            curBit = curBit shr 1
        }
        return idx - 1
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