private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

fun go() {
    val n = readInt()
    val a = readInts()

    var b1 = 0
    var b2 = 0

    var ans = 0
    for (v in a) {
        if (v >= b1) {
            b2 = b1
            b1 = v
        } else if (v >= b2) {
            b2 = v
        } else {
            ans ++
        }
    }
    outputLn("${ans}")
}

fun main() {
    go()
    println(OUTPUT_LINES.joinToString("\n"))
}