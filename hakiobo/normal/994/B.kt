import java.io.BufferedReader
import java.util.PriorityQueue

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val k = br.readInt()
    val powers = IntArray(n) { br.readInt() }
    val coins = LongArray(n){br.readInt().toLong()}
    val answers = LongArray(n)
    val pq = PriorityQueue<Long>()
    var curSum = 0L
    val sorted = (0 until n).sortedBy { powers[it] }
    for (person in sorted) {
        answers[person] = coins[person] + curSum
        curSum += coins[person]
        pq += coins[person]
        while (pq.size > k) {
            curSum -= pq.poll()
        }
    }
    println(answers.joinToString(" "))
}

private const val SPACE_INT = ' '.toInt()
private const val ZERO_INT = '0'.toInt()
private const val NL_INT = '\n'.toInt()

private fun BufferedReader.readInt(): Int {
    var ret = read()
    while (ret <= SPACE_INT) {
        ret = read()
    }
    val neg = ret == '-'.toInt()
    if (neg) {
        ret = read()
    }
    ret -= ZERO_INT
    var read = read()
    while (read >= ZERO_INT) {
        ret *= 10
        ret += read - ZERO_INT
        read = read()
    }

    while (read <= SPACE_INT && read != -1 && read != NL_INT) {
        mark(1)
        read = read()
    }
    if (read > SPACE_INT) {
        reset()
    }
    return if (neg) -ret else ret
}