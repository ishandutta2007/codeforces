import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    val T = readInt()

    for (test in  1..T) {
        val N = readInt()

        val rules = (1..N).map { idx -> 
            val (a, b, match) = readStrings()
            Triple(a.reversed(), b.reversed(), match.toInt())
        }

        val max_length = rules.maxOf { max(it.first.length, it.second.length) }

        var good = max_length

        var bad: Int = -1
        for ((a, b, c) in rules) {
            var i = 0
            while (i < a.length && i < b.length && a[i] == b[i]) {
                ++i
            }
            if (c == 0) {
                bad = max(bad, i)
            } else {
                good = min(good, i)
            }
        }
        
        if (good <= bad) {
            println(0)
        } else {
            println(good - bad)
            for (i in (bad + 1)..good) {
                print("$i ")
            }
            println()
        }
    }
}