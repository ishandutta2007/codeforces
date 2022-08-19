private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

fun go() {
    val (n, a, b, k) = readInts()
    val cnts = mutableMapOf<Int, Int>()

    var ans = 0
    if (a >= b) {
        // normal sort order
        readInts().forEach{ cnts[it] = (cnts[it] ?: 0) + 1 }
        cnts.keys.sorted().forEach {
            if (it * k in cnts) {
                val v = minOf(cnts[it]!! / a, cnts[it * k]!! / b)
                ans += v
                cnts[it * k] = cnts[it * k]!! - v * b
            }
        }
    } else {
        // reverse sort order
        readInts().forEach{ cnts[-it] = (cnts[-it] ?: 0) + 1 }
        cnts.keys.sorted().forEach {
            if (it % k == 0 && it / k in cnts) {
                val v = minOf(cnts[it / k]!! / a, cnts[it]!! / b)
                ans += v
                cnts[it / k] = cnts[it / k]!! - v * a
            }
        }
    }
    outputLn("${ans}")

}

fun main() {
    go()
    println(OUTPUT_LINES.joinToString("\n"))
}