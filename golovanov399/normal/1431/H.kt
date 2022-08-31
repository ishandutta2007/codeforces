import kotlin.math.*

fun solve() {
    val (n, m, k) = readLine()!!.split(' ').map(String::toInt)
    val a = readLine()!!.split(' ').map(String::toLong).toLongArray()
    val b = readLine()!!.split(' ').map(String::toLong).toLongArray()
    var c = Array(n) { IntArray(0) }
    for (i in 0 until n) {
        c[i] = readLine()!!.split(' ').map(String::toInt).toIntArray()
    }
    var pc = c
    for (i in 0 until n) {
        for (j in 0 until m) {
            if (i > 0) {
                pc[i][j] = max(pc[i][j], pc[i - 1][j])
            }
            if (j > 0) {
                pc[i][j] = max(pc[i][j], pc[i][j - 1])
            }
        }
    }
    var l = 0
    var r = 0
    while (l < n && a[l] == 0L) {
        l += 1
    }
    while (r < m && b[r] == 0L) {
        r += 1
    }
    if (l == n && r == m) {
        println(0)
        return
    }
    var toUnlock = LongArray(n + m - l - r) { 0L }
    var mxs = IntArray(n + m - l - r) { 0 }
    var ptr = 0
    while (l < n || r < m) {
        mxs[ptr] = pc[l - 1][r - 1]
        if (l < n && r < m) {
            if (a[l] < b[r]) {
                toUnlock[ptr] = a[l]
                l += 1
            } else {
                toUnlock[ptr] = b[r]
                r += 1
            }
        } else if (l < n) {
            toUnlock[ptr] = a[l]
            l += 1
        } else {
            toUnlock[ptr] = b[r]
            r += 1
        }
        ptr += 1
    }

    var ans = Long.MAX_VALUE
    for (idx in toUnlock.indices) {
        var cur = 0L
        var raids = 0L
        var mx = 0
        for (i in toUnlock.indices) {
            val cand = mxs[i] + (if (i == idx) k else 0)
            mx = max(mx, cand)
            if (toUnlock[i] <= cur) {
                continue
            }
            if (mx == 0) {
                raids = Long.MAX_VALUE
                break
            }
            val tmp = (toUnlock[i] - cur + mx - 1) / mx
            cur += tmp * mx
            raids += tmp
        }
        ans = min(ans, raids)
    }
    println(ans)
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}