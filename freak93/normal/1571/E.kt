import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

val infinite = 100000000

fun main() {
    val T = readInt()

    for (test in 1..T) {
        val N = readInt()

        val S = readLn()
        val A = readLn()

        var goodMasks = BooleanArray(16)
        goodMasks[5] = true
        goodMasks[3] = true

        val next = IntArray(16)
        val prev = IntArray(16)

        for (i in N - 1 downTo 0) {
            for (j in 0..15) {
                prev[j] = next[j]
                next[j] = infinite
            }
        
            for (j in 0..15) {
                var state = j / 2
                if (S[i] == ')')
                    state += 8
                next[state] = min(next[state], prev[j])
                next[state xor 8] = next[state] + 1
            }
            if (i < N - 3) {
                val need = (A[i] == '1')
                if (!need) 
                    continue
                for (j in 0..15) {
                    if (goodMasks[j] != need)
                    next[j] = infinite
                }
            }
        }

        var answer = next.minOf { it }
        if (answer == infinite) {
            answer = -1
        }

        println(answer)
    }
}