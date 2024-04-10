fun solve() {
    val n = readLine()!!.toInt()
    val p = readLine()!!.split(' ').map { it.toInt() - 1 }
    if (n == 1) {
        println("-1")
        return
    }
    val used = MutableList(n) { false }
    val q = MutableList(n) { -1 }
    fun rec(i: Int): Boolean {
        if (i == n) {
            println(q.map(Int::inc).joinToString(" "))
            return true
        }
        for (j in 0 until n) {
            if (!used[j] && j != p[i]) {
                q[i] = j
                used[j] = true
                if (rec(i + 1)) {
                    return true
                }
                used[j] = false
            }
        }
        return false
    }
    rec(0)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}