private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
    var tests = readLine()!!.toInt()
    while (tests-- > 0) {
        val (n, k) = readInts()
        println((0 until n).map {'a' + (it % k)}.joinToString(""))
    }
}