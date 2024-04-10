private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
    var T = readLine()!!.toInt()
    while (T-- > 0) {
        val (a, b, k) = readInts()
        println(if (k % 2 == 0) (a - b).toLong() * (k / 2) else (a - b).toLong() * (k / 2) + a)
    }
}