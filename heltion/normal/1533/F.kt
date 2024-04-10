fun main() {
    fun readInt() = readLine()!!.toInt()
    fun readInts() = readLine()!!.split(' ').map { it.toInt() }
    val s = readLine()!!
    val n = s.length
    val nxt = Array(2){
        IntArray(n){
            n
        }
    }
    val pos = Array(2){
        arrayListOf<Int>()
    }
    for (i in 0 until n) {
        if (s[i] == '0') nxt[0][i] = pos[0].size
        if (s[i] == '1') nxt[1][i] = pos[1].size
        pos[s[i] - '0'].add(i)
    }
    for (i in n - 2 downTo 0) {
        if (nxt[0][i] == n) nxt[0][i] = nxt[0][i + 1]
        if (nxt[1][i] == n) nxt[1][i] = nxt[1][i + 1]
    }
    for (k in 1..n){
        var ans = 0
        var cur = 0
        while (cur < n) {
            ans += 1
            val nxt0 = nxt[0][cur]
            if (nxt0 == n) break
            if (nxt0 + k >= pos[0].size) break
            val nxtK0 = pos[0][nxt0 + k]
            val nxt1 = nxt[1][cur]
            if (nxt1 == n) break
            if (nxt1 + k >= pos[1].size) break
            val nxtK1 = pos[1][nxt1 + k]
            cur = maxOf(nxtK0, nxtK1)
        }
        print("$ans ")
    }
}