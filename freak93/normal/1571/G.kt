import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

private val inf = 1_000_000_000_000_000L

// For (X, BX) and (Y, BY) to both get bonus
// X < Y
// BY <= BX
// Y - X - 1 >= BX - BY => BY + Y > BX + X

private class FenwickTree(val size: Int) {
    val data = LongArray(size) { -inf }

    fun update(pos: Int, value: Long) {
        var p = pos + 1

        while (p <= size) {
            data[p - 1] = max(data[p - 1], value)
            p += (p and -p)
        }
    }

    fun query(pos: Int): Long {
        var best = - inf
        var p = pos + 1

        while (p > 0) {
            best = max(best, data[p - 1])
            p -= (p and -p)
        }
        return best
    }
}

fun main() {
    val (n, m) = readInts()

    val events = (1..n).map { warrior ->
        val k = readInt()
        val a = readInts()
        val b = readInts()
        (a zip b).map { (x, y) -> Triple(x, y, warrior - 1) }
    }.flatten().sortedWith(compareBy({ it.second }, { -(it.second + it.third) })).asReversed()

    val F = FenwickTree(n + m + 3)
    var answer = 0L
    for ((a, b, idx) in events) {
        var best = F.query(b + idx - 1)
        if (idx >= m - b) {
            best = max(best, 0)
        }
        best += a
        F.update(b + idx, best)
        answer = max(answer, best)
    }

    println(answer)
}