private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main() {
    var a1 = readInt()
    var a2 = readInt()
    var k1 = readInt()
    var k2 = readInt()
    var n = readInt()
    var maxv: Int = 0
    var minv: Int = 1000000000
    for (i in 0..a1) {
        if (i * k1 > n)
            break
        maxv = Math.max(maxv, i + Math.min(a2, (n - i * k1) / k2))
    }
    n -= (k1 - 1) * a1 + (k2 - 1) * a2
    minv = Math.min(a1 + a2, n)
    minv = Math.max(0, minv)
    println(minv.toString() + " " + maxv)
}