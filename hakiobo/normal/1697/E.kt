import java.io.BufferedReader
import kotlin.math.absoluteValue
import kotlin.math.min

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
    val mod = 998_244_353L
    val facts = LongArray(101)
    facts[0] = 1L
    for (i in 1..100) {
        facts[i] = (facts[i - 1] * i) % mod
    }
    val invFacts = LongArray(101)
    invFacts[100] = modPow(facts[100], mod - 2, mod)
    for (i in 100 downTo 1) {
        invFacts[i - 1] = (i * invFacts[i]) % mod
    }
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val xs = IntArray(n)
    val ys = IntArray(n)
    for (i in 0 until n) {
        xs[i] = br.readInt()
        ys[i] = br.readInt()
    }
    val potentialGroupSizes = mutableListOf<Int>()
    val dists = Array(n) { i ->
        IntArray(n) { j ->
            (xs[i] - xs[j]).absoluteValue + (ys[i] - ys[j]).absoluteValue
        }
    }
    val sorted = Array(n) { i -> (0 until n).sortedBy { j -> dists[i][j] } }
    for (baseIndex in 0 until n) {
        val closestDist = dists[baseIndex][sorted[baseIndex][1]]
        val closest = mutableListOf<Int>()
        var good = true
        for (i in sorted[baseIndex]) {
            if (dists[baseIndex][i] <= closestDist) {
                if (i < baseIndex) good = false
                closest += i
            } else {
                break
            }
        }
        if (good) {
            for (idx in 1 until closest.size) {
                val i = closest[idx]
                if (closestDist != dists[i][sorted[i][1]]) good = false
                val closest2 = mutableListOf<Int>()
                for (j in sorted[i]) {
                    if (dists[i][j] <= closestDist) {
                        closest2 += j
                    } else {
                        break
                    }
                }
                closest2.sort()
                if (closest.size != closest2.size) good = false
                for (j in 0 until min(closest.size, closest2.size)) {
                    if (closest[j] != closest2[j]) good = false
                }
            }
        }
        if (good) {
            potentialGroupSizes += closest.size
        }
    }
    val knapsack = LongArray(n + 1)
    knapsack[0] = 1
    for (size in potentialGroupSizes) {
        for (i in n downTo size - 1) {
            knapsack[i] += knapsack[i - size + 1]
            knapsack[i] %= mod
        }
    }
    var ans = 0L
    for (i in 0..n) {
        val toAdd = (facts[n] * invFacts[i]) % mod
        ans += toAdd * knapsack[i]
        ans %= mod
    }
    println(ans)
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