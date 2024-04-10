private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

fun go(): Boolean {
    val N = readInt()
    val S = readLn()

    val mp = mutableMapOf<Char, Int>()

    for (c in S) {
        mp[c] = (mp[c] ?: 0) + 1
    }

    if (mp.size == 1) {
        return true
    } else {
        for (e in mp) {
            if (e.value > 1) {
                return true
            }
        }
        return false
    }
}

fun main() {
    outputLn(if (go()) "Yes" else "No")
    println(OUTPUT_LINES.joinToString("\n"))
}