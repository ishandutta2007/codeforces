private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

fun go() {
    val (N, M) = readInts()

    val A = readInts()
    val pref = mutableListOf(0)
    for (a in A) {
        pref.add(pref[pref.size - 1] + a)
    }

    val Q = readInt()

    for (q in 1..Q) {
        var W = readInts()
        W = W.subList(1, W.size) + listOf(M+1)
        var i = 0
        var l = 0
        for (r in W) {
            val g = (r - l - 1)
            var mi = i
            var ma = pref.size
            while (ma - mi > 1) {
                var md = (mi + ma) / 2
                if (pref[md] - pref[i] <= g) {
                    mi = md
                } else {
                    ma = md
                }
            }
            i = mi

            l = r
        }
        outputLn(if (i == pref.size-1) "YES" else "NO")
    }

}

fun main() {
    go()
    println(OUTPUT_LINES.joinToString("\n"))
}