private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun check(x: Int): Int {
    var n = x
    while (n % 10 == 0)
        n = n / 10
    return n
}

fun main() {
    var n = readInt()
    var mc: MutableSet<Int> = mutableSetOf()
    while (true) {
        if (mc.contains(n))
            break
        mc.add(n)
        n = check(n + 1)
    }
    println(mc.size)
}