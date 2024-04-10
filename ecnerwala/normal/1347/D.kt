private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

fun go() {
    val N = readInt()
    val A = readInts()

    var numTurns = 0

    var st = 0
    var en = N
    var last = 0

    while (st < en) {
        var current = 0
        while (current <= last && st < en) {
            if (numTurns % 2 == 0) current += A[st++]
            else current += A[--en]
        }
        numTurns++
        last = current
    }

    var aTot = 0
    for (i in 0..st-1) {
        aTot += A[i]
    }
    var bTot = 0
    for (i in en..N-1) {
        bTot += A[i]
    }

    outputLn("${numTurns} ${aTot} ${bTot}")
}

fun main() {
    val T = readInt()
    for (i in 1..T) go()
    println(OUTPUT_LINES.joinToString("\n"))
}