import kotlin.math.*
import kotlin.system.exitProcess

fun isRepresentable(_n: Int): Boolean {
    var n = _n
    for (i in 2..9) {
        while (n % i == 0) {
            n /= i
        }
    }
    return n == 1
}

fun main() {
    val (m, k) = readLine()!!.split(' ').map(String::toInt)
    if (!isRepresentable(m)) {
        println(-1)
        exitProcess(0)
    }

    var divs = mutableListOf<Int>()
    var d = 1
    while (d * d <= m) {
        if (m % d == 0) {
            divs.add(d)
            if (d * d < m) {
                divs.add(m / d)
            }
        }
        d += 1
    }
    divs.sort()

    val sz = divs.size
    val trans = List(sz) { i -> IntArray(10) { c -> if (c > 0 && divs[i] % c == 0) divs.binarySearch(divs[i] / c) else -1 } }
    var edges = mutableListOf<Pair<Int, Int>>()
    for (i in 0 until sz) {
        for (j in 0 until 10) {
            if (trans[i][j] > -1) {
                edges.add(Pair(i, j))
            }
        }
    }

    var current: Long = 0
    var dp = MutableList(1) { LongArray(sz) { 0 } }
    dp[0][0] = 1L
    while (true) {
        var layer = LongArray(sz) { 0 }
        for ((from, c) in edges) {
            layer[from] += dp.last()[trans[from][c]]
        }
        if (current + layer.last() < k.toLong()) {
            current += layer.last()
            dp.add(layer)
        } else {
            break
        }
    }
    val len = dp.size
    var cur = divs.size - 1
    for (i in 0 until len) {
        for (c in 1..9) {
            if (trans[cur][c] == -1) {
                continue
            }
            if (current + dp[len - 1 - i][trans[cur][c]] < k) {
                current += dp[len - 1 - i][trans[cur][c]]
            } else {
                print(c)
                cur = trans[cur][c]
                break
            }
        }
    }
    println()
}