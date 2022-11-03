private const val MOD = 998244353L

fun main() {
    val br = System.`in`.bufferedReader()
    val s = br.readLine()
    val t = br.readLine()
    val m = t.length
    val dpA = Array(s.length) {
        LongArray(t.length + 1) { -1L }
    }
    val dpB = Array(t.length) {
        LongArray(t.length) { -1L }
    }

    fun solveA(sID: Int, tID: Int): Long {
        if (sID == s.length) {
            return if (tID == m) 1L else 0L
        }
        if (dpA[sID][tID] == -1L) {
            var ways = 0L
            if (tID == m) {
                ways++
            } else if (s[sID] == t[m - 1 - tID]) {
                ways += solveA(sID + 1, tID + 1)
            }
            ways += solveA(sID + 1, tID)
            if (tID == 0) {
                ways += solveA(sID + 1, tID)
            }

            dpA[sID][tID] = ways % MOD
        }
        return dpA[sID][tID]
    }

    fun solveB(start: Int, end: Int): Long {
        if (dpB[start][end] == -1L) {
            val sID = end - start + 1
            var ways = 0L
            if (end == m - 1) {
                ways = solveA(sID, sID)
            } else {
                if (start != 0 && s[sID] == t[start - 1]) {
                    ways += solveB(start - 1, end)
                }
                if (s[sID] == t[end + 1]) {
                    ways += solveB(start, end + 1)
                }
            }
            dpB[start][end] = ways % MOD
        }
        return dpB[start][end]
    }

    var ways = 0L
    for (i in t.indices) {
        if (t[i] == s[0]) {
            ways += solveB(i, i) shl 1
            ways %= MOD
        }
    }

    ways += solveA(1, 0) shl 1
    print(ways % MOD)
}