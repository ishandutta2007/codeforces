private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    var T = readInt()

    while (T > 0) {
        T -= 1;

        val input = readLn()

        val small = input.count { it == '<' }
        val larger = input.count { it == '>' }

        val answer = if (small == 0 && larger == 0) {
            '='
        } else if (larger == 0) {
            '<'
        } else if (small == 0) {
            '>'
        } else {
            '?'
        }

        println(answer)
    }
}