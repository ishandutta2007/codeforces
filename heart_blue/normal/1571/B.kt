private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles


fun main() {
    var ncase = readInt()
    while (ncase-- > 0) {
        var n = readInt()
        var (a, va) = readInts()
        var (c, vc) = readInts()
        var b = readInt()
        var ans = 0
        for (vb in va..vc) {
            if (vb - va <= b - a && vc - vb <= c - b) {
                ans = vb
                break
            }
        }
        println(ans)
    }
}