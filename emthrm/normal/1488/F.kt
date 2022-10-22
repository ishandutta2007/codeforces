fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    val c = readLine()!!.split(" ").map{ it.toInt() }
    val q = readLine()!!.toInt()
    var l = IntArray(q) { -1 }
    var r = IntArray(q) { -1 }
    var cnt = IntArray(n) { 0 }
    for (i in 0 until q) {
        val (li, ri) = readLine()!!.split(" ").map{ it.toInt() - 1 }
        l[i] = li
        r[i] = ri
        ++cnt[ri]
    }
    var rs = Array(n, { IntArray(cnt[it]) { -1 } })
    var idx = IntArray(n) { 0 }
    for (i in 0 until q) {
        rs[r[i]][idx[r[i]]] = i
        ++idx[r[i]]
    }
    var pos = IntArray(n) { n + it }
    var cost = IntArray(n) { 0 }
    var sum = LongArray(n) { 0L }
    var ans = LongArray(q) { 0L }
    var index = -1
    for (i in 0 until n) {
        var cur_pos = i
        while (index >= 0 && cost[index] <= c[i]) {
            cur_pos = pos[index]
            --index
        }
        ++index
        pos[index] = cur_pos
        cost[index] = c[i]
        if (index == 0) {
            sum[index] = c[i].toLong() * (i + 1)
        } else {
            sum[index] = sum[index - 1] + c[i].toLong() * (i - cur_pos + 1)
        }
        rs[i].forEach {
            ans[it] = sum[index]
            if (l[it] > 0) {
                var lb = 0
                var ub = index + 1
                while (ub - lb > 1) {
                    var mid = (lb + ub) / 2
                    if (pos[mid] <= l[it]) {
                        lb = mid
                    } else {
                        ub = mid
                    }
                }
                if (pos[lb] == l[it]) {
                    ans[it] -= sum[lb - 1]
                } else {
                    ans[it] -= sum[lb]
                    if (lb == index) {
                        ans[it] += cost[lb].toLong() * (i + 1 - l[it])
                    } else {
                        ans[it] += cost[lb].toLong() * (pos[lb + 1] - l[it])
                    }
                }
            }
        }
    }
    println(ans.joinToString(" "))
}