
fun solve() {
    val (n, s) = readLongs()

    fun can(last: Long) : Boolean {
        var curNumber = last
        var curN = n
        var curS = 0L
        while (curS <= s && curN > 0) {
            if (curNumber == 1L) {
                curS += curN
                break
            }
            curS += curNumber
            curN--
            curNumber = (curNumber + 1) / 2
        }
        return curS <= s
    }

    var left = (s + n - 1) / n
    var right = s
    while (left + 1 < right) {
        val middle = (left + right) / 2
        if (can(middle)) {
            left = middle
        } else {
            right = middle
        }
    }
    println(left)
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