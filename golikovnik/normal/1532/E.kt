fun solve() {
    readInt()
    val a = ArrayList(readInts())
    val mx = a.indices.maxByOrNull { a[it] }!!
    val mxValue = a[mx]
    val sum = a.sumOf { it.toLong() }
    val result = ArrayList<Int>()
    for (i in a.indices) {
        if (i != mx && 2L * mxValue == sum - a[i]) {
            result.add(i)
        }
    }
    a.removeAt(mx)
    if (2L * a.maxOrNull()!! == sum - mxValue) result.add(mx)
    println(result.size)
    println(result.map { it + 1 }.joinToString(" "))
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