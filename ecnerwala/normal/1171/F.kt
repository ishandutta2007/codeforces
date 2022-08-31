private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

fun go() {
    val n = readInt()
    val ranges = mutableListOf<Pair<Pair<Int, Int>, Int>>();
    for (i in 0..n-1) {
        val (l, r) = readInts()
        ranges += (l to r) to i
    }
    ranges.sortBy {it.first.first}

    val output = MutableList<Int>(n){0}
    var hi = ranges[0].first.second
    for (i in 1..n-1) {
        if (hi < ranges[i].first.first) {
            for (j in 0..i-1) {
                output[ranges[j].second] = 1
            }
            for (j in i..n-1) {
                output[ranges[j].second] = 2
            }
            outputLn(output.joinToString(" "))
            return
        } else {
            hi = maxOf(hi, ranges[i].first.second)
        }
    }
    outputLn("-1")
}

fun main() {
    val T = readInt()
    for (t in 1..T) { go() }
    println(OUTPUT_LINES.joinToString("\n"))
}