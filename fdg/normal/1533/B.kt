import java.lang.Integer.max

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
    var tests = readInt()
    while (tests-- > 0) {
        val n = readInt()
        val arr = readInts()
        println(if ((2..n).map { (arr[it - 1] - arr[it - 2]) % 2 }.minOrNull() == 0) "YES" else "NO")
    }
}