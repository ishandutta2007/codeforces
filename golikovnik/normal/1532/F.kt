fun solve() {
    val n = readInt()
    val a = (0 until 2 * n - 2).map { readLn() }
    val big = a.filter { it.length == n - 1 }

    fun trySolve(s1 : String, s2 : String): Boolean {
        if (!s2.startsWith(s1.substring(1))) {
            return false
        }
        val s = s1 + s2.last()
        val ans = CharArray(2 * n - 2) { 'Z' }
        for (len in 1 until n) {
            val it = a.indexOf(s.take(len))
            if (it < 0) return false
            ans[it] = 'P'
            val jt = a.lastIndexOf(s.takeLast(len))
            if (jt < 0) return false
            ans[jt] = 'S'
        }
        if (ans.any { it == 'Z' }) return false
        print(ans.joinToString(""))
        return true
    }

    val x = big[0]
    val y = big[1]
    if (!trySolve(x, y)) trySolve(y, x)
}

fun main() {
//    repeat(readInt()) {
        solve()
//    }
}

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles