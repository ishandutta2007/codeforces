private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
    val n = readInt()
    val arr = readInts()
    val sum = arr.sumOf { it.toLong() }

    val ret: MutableList<Int> = emptyList<Int>().toMutableList()
    val srt = arr.withIndex().sortedBy { it.value }
    for (i in 1..n) {
        val maxEl = if (i == n) srt[n - 2].value else srt[n - 1].value
        if (2.toLong() * maxEl == sum - srt[i - 1].value) ret.add(srt[i - 1].index + 1)
    }
    println(ret.size)
    println(ret.joinToString(" "))
}