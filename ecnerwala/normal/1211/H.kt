private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

private fun go() {
    val N = readInt()
    val adj = MutableList(N) {mutableListOf<Pair<Int, Int>>()}
    (0..N-2).forEach {
        val (x,y) = readInts()
        adj[x-1].add(y-1 to it)
        adj[y-1].add(x-1 to it)
    }

    var R = 0

    fun dfs(cur: Int, prv: Int = -1): Int {
        val ch = mutableListOf<Int>()
        for ((nxt, e) in adj[cur]) {
            if (nxt == prv) continue
            val v = dfs(nxt, cur) + 1
            ch.add(v)
        }

        var totV = 0
        for (v in ch) {
            totV += v
        }

        val dp = MutableList(totV + 1){R+1}
        dp[0] = 0

        totV = 0

        for (v in ch) {
            for (a in totV + v downTo 0) {
                dp[a] = dp[a] + v
                if (a >= v) dp[a] = minOf(dp[a], dp[a-v])
            }
            totV += v
        }

        var ans = R+1
        for (a in 0..minOf(R, totV)) {
            ans = minOf(ans, dp[a])
        }
        return ans
    }

    fun isGood(R_: Int): Boolean {
        R = R_
        return dfs(0) <= R
    }

    var mi = 0
    var ma = N+1
    while (ma - mi > 1) {
        val md = (mi + ma) / 2
        if (isGood(md)) {
            ma = md
        } else {
            mi = md
        }
    }

    val coloring = MutableList(N-1){-1}

    fun dfs_coloring(cur: Int, prv: Int = -1): MutableList<Int> {
        val ch = mutableListOf<MutableList<Int>>()
        for ((nxt, e) in adj[cur]) {
            if (nxt == prv) continue
            val v = dfs_coloring(nxt, cur)
            v.add(e)
            ch.add(v)
        }

        var totV = 0
        for (v in ch) {
            totV += v.size
        }

        val dp = mutableListOf(mutableListOf(0 to false))
        totV = 0

        for (v in ch) {
            val pdp = dp[dp.size - 1]
            dp.add(MutableList(totV + v.size + 1){
                var resp = (if (it <= totV) pdp[it].first + v.size else R+1) to false
                if (it >= v.size && pdp[it - v.size].first < resp.first) {
                    resp = pdp[it - v.size].first to true
                }
                resp
            })
            totV += v.size
        }
        var ans = R+1
        var bestTake = -1
        for (a in 0..minOf(R, totV)) {
            val cnd = dp[dp.size - 1][a].first
            if (cnd < ans) {
                ans = cnd
                bestTake = a
            }
        }
        if (bestTake == -1) {
            return MutableList(R+1){0}
        } else {
            val resp = mutableListOf<Int>()
            for (i in dp.size - 2 downTo 0) {
                if (dp[i+1][bestTake].second) {
                    // color them all
                    for (e in ch[i]) {
                        coloring[e] = cur
                        bestTake --
                    }
                } else {
                    resp.addAll(ch[i])
                }
            }
            return resp
        }
    }

    R = ma
    dfs_coloring(0)

    outputLn("${ma}")
    outputLn(coloring.map{it+2}.joinToString(" "))
}

fun main() {
    val T = readInt()
    (1..T).forEach {
        go()
    }
    println(OUTPUT_LINES.joinToString("\n"))
}