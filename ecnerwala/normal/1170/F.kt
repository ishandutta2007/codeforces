private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of ints

private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

fun go() {
    val (N, M, K) = readInts()
    val A = readLongs().sorted()
    val pref = mutableListOf<Long>(0)
    for (a in A) {
        pref += (pref[pref.size - 1] + a)
    }
    var ans = 2e18.toLong()
    for (x in 0..N-M) {
        val y = x + M

        var mi = x
        var ma = y

        while (ma - mi > 1) {
            val md = (mi + ma) / 2
            if (A[md] * (md - x) - (pref[md] - pref[x]) <= K) {
                mi = md
            } else {
                ma = md
            }
        }
        val m = minOf(mi, (x + y) / 2)
        var inf = A[m] * (m - x) - (pref[m] - pref[x])
        var def = (pref[y] - pref[m]) - A[m] * (y - m)
        if ((m - x + 1) < (y - m - 1)) {
            // we want to increase A[m] if possible, up to A[m+1]
            val v = minOf(A[m+1] - A[m], (K.toLong() - inf) / (m - x + 1))
            inf += v * (m - x + 1)
            def -= v * (y - m - 1)
        }
        ans = minOf(ans, inf + def)
    }
    outputLn("${ans}")
}

fun main() {
    go()
    println(OUTPUT_LINES.joinToString("\n"))
}