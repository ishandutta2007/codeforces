import java.lang.Integer.max

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
    var tests = readInt()
    while (tests-- > 0) {
        val (n, k) = readInts()
        var s = readLn()
        var need = s.sumOf { it - '0' }

        var iter = 0
        while (need > 0) {
            if (s[iter] == '1') --need
            s = s.removeRange(iter, iter + 1)
            if (s.isNotEmpty()) iter = (iter + k - 1) % s.length
        }
        println(n - s.length)
    }
}