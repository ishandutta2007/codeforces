private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

fun go(): Boolean {
    val S = readLn().toCharArray()
    val T = readLn().toCharArray()
    var i = 0
    var j = 0
    while (j < T.size) {
        if (i >= S.size) return false

        if (T[j] == '-') {
            if (S[i] == '-') {
                i++
                j++
            } else {
                return false
            }
        } else {
            if (S[i] == '+') {
                i++
                j++
            } else {
                if (i + 1 < S.size && S[i+1] == '-') {
                    i += 2
                    j++
                } else {
                    return false
                }
            }
        }
    }
    return i == S.size
}

fun main() {
    val T = readInt()
    for (i in 1..T) outputLn(if (go()) "YES" else "NO")
    println(OUTPUT_LINES.joinToString("\n"))
}