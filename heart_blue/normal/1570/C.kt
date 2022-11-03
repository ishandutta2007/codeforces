private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main() {
    var n = readInt()
    var a = readInts()
    var v = Array<Pair<Int, Int>>(n, { Pair<Int, Int>(0, 0) })
    for (i in 0 until n) {
        v[i] = Pair<Int, Int>(a[i], i + 1);
    }
    v.sortWith(compareBy({ -it.first }, { it.second }))
    var ans = 0
    var key = Array<Int>(n, { 0 })
    for (i in 0 until n) {
        ans = i * v[i].first + 1 + ans
        key[i] = v[i].second
    }
    println(ans)
    println(key.joinToString (" " ))
}