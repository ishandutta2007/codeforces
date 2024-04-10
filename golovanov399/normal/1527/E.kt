import kotlin.math.*

class SegTree(_n: Int) {
    val n = 1 shl (32 - (_n - 1).countLeadingZeroBits())
    val a = IntArray(n + n) { 0 }
    val ad = IntArray(n + n) { 0 }

    fun push(v: Int) {
        if (ad[v] > 0) {
            for (t in 0..1) {
                ad[v * 2 + t] += ad[v]
                a[v * 2 + t] += ad[v]
            }
            ad[v] = 0
        }
    }

    fun _add(v: Int, l1: Int, r1: Int, l: Int, r: Int, x: Int): Int {
        if (l >= r1 || l1 >= r) {
            return 0
        }
        if (l <= l1 && r >= r1) {
            a[v] += x
            ad[v] += x
            return a[v]
        }
        push(v)
        val m = (l1 + r1) / 2
        val res = max(_add(v + v, l1, m, l, r, x), _add(v + v + 1, m, r1, l, r, x))
        a[v] = max(a[v + v], a[v + v + 1])
        return res
    }

    fun add(l: Int, r: Int, x: Int): Int = _add(1, 0, n, l, r, x)

    fun _get(v: Int, l1: Int, r1: Int, l: Int, r: Int): Int {
        if (l >= r1 || l1 >= r) {
            return 0
        }
        if (l <= l1 && r >= r1) {
            return a[v]
        }
        push(v)
        val m = (l1 + r1) / 2
        return max(_get(v + v, l1, m, l, r), _get(v + v + 1, m, r1, l, r))
    }

    fun set(pos: Int, x: Int) {
        var (v, l, r) = listOf(1, 0, n)
        while (l + 1 < r) {
            push(v)
            val m = (l + r) / 2
            if (pos < m) {
                r = m
                v *= 2
            } else {
                l = m
                v = v * 2 + 1
            }
        }
        a[v] = x
        while (v > 1) {
            v /= 2
            a[v] = max(a[v + v], a[v + v + 1])
        }
    }

    fun get(l: Int, r: Int): Int = _get(1, 0, n, l, r)
}

class Fenwick(val n: Int) {
    val a = IntArray(n) { 0 }

    fun remax(pos: Int, x: Int) {
        var i = pos
        while (i < n) {
            a[i] = max(a[i], x)
            i = i or (i + 1)
        }
    }

    fun get(pos: Int): Int {
        var res = 0
        var i = pos
        while (i >= 0) {
            res = max(res, a[i])
            i = (i and (i + 1)) - 1
        }
        return res
    }
}

fun solve() {
    val (n, k) = readLine()!!.split(' ').map(String::toInt)
    val a = readLine()!!.split(' ').map(String::toInt)

    val last = mutableMapOf<Int, Int>()
    var total = 0
    val prv = IntArray(n) { -1 }
    val p = IntArray(n) { 0 }
    for ((i, x) in a.withIndex()) {
        if (last.containsKey(x)) {
            val j = last[x]!!
            total += i - j
            p[j] += i - j
            prv[i] = j
        }
        last[x] = i
    }

    val dp = IntArray(n + 1) { 0 }
    val tmp = IntArray(n + 1) { 0 }

    repeat (k - 1) {
        val tree = SegTree(n)
        var cur = 0
        for (i in 0 until n) {
            tree.add(i, i + 1, dp[i])
//            tree.set(i, dp[i])
            var nw = dp[i]
            if (prv[i] > -1) {
                nw += i - prv[i]
                cur = max(cur, tree.add(prv[i] + 1, i + 1, i - prv[i]))
            }
            cur = max(cur, nw)
            // dp[i] = max(dp[j] + sum{x > j: prv[x] <= j})
            tmp[i + 1] = cur
        }
        for (i in 0..n) {
            dp[i] = tmp[i]
        }
    }

    println(total - dp[n])
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}