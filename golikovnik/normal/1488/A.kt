
fun main() {
    repeat(readInt()) {
        val (x, y) = readInts()
        var ans = 0
        val powers = ArrayList<Int>()
        var cur = 1
        repeat(10) {
            powers.add(cur)
            cur *= 10
        }
        var k = 0L
        for (pw in powers.reversed()) {
            val add = 1L * x * pw
            while (k + add <= y) {
                k += add.toInt()
                ans += 1
            }
        }
        println(ans + y - k)
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