
fun f(L: Int, M: Int, R: Int): Int {
    return when (M) {
        L -> R - L
        R -> R - L
        else -> {
            minOf(R - M, M - L) + (R - L)
        }
    }
}

fun solve() {
    var (n, x, y) = readInts()
    if (x > y) {
        x = y.also { y = x }
    }
    var ans = 1e8.toInt()
    for (pref in 1 until n) {
        if (x > pref || y < pref + 1) continue
        ans = minOf(ans, maxOf(f(1, x, pref), f(pref + 1, y, n)))
    }
    println(ans)
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