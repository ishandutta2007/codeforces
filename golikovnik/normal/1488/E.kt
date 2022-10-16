
fun solve() {
    val n = readInt()
    val a = readInts()
    data class Segment(val from: Int, val to: Int)
    val segments = ArrayList<Segment>()
    val mp = HashMap<Int, Int>()
    for (i in a.indices) {
        val v = a[i]
        if (v in mp) {
            segments.add(Segment(mp[v]!!, i))
            mp.remove(v)
        } else {
            mp[v] = i
        }
    }
    for (i in 0 until n) {
        segments.add(Segment(i, i))
    }

    val dp = Array(n) { 0 }

    fun update(at: Int, v: Int) {
        var curAt = at
        while (curAt < n) {
            dp[curAt] = maxOf(dp[curAt], v)
            curAt = curAt or curAt + 1
        }
    }
    fun get(r: Int): Int {
        var ans = 0
        var curR = r
        while (curR >= 0) {
            ans = maxOf(ans, dp[curR])
            curR = (curR and (curR + 1)) - 1
        }
        return ans
    }

    for (seg in segments.sortedByDescending { it.from }) {
        update(seg.to, get(seg.to - 1) + if (seg.from == seg.to) 1 else 2)
    }
    println(dp.maxOrNull()!!)
}

fun main() {
    repeat(readInt()) {
        solve()
    }
}

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles