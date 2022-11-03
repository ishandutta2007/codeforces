import java.io.BufferedReader
import java.time.Instant
import kotlin.random.Random

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val m = br.readInt()
    val p = br.readInt()
    var fAnswer = 0L
    val likes = LongArray(n) { br.readLine().toLong(2) }
    val req = (n + 1) shr 1
    val random = Random(Instant.now().nano)
    repeat(50) {

        val idealAnswer = likes[random.nextInt(n)]
        val maxPossible = idealAnswer.countOneBits()
        val states = IntArray(1 shl maxPossible)
        val map = IntArray(m) { -1 }
        val revMap = IntArray(maxPossible)
        var ct = 0
        for (x in 0 until m) {
            if (((1L shl x) and idealAnswer) != 0L) {
                revMap[ct] = x
                map[x] = ct++
            }
        }

        for (like in likes) {
            var t = like and idealAnswer
            var k = 0
            while (t != 0L) {

                val x = t.countTrailingZeroBits()
                val y = map[x]
                k = k or (1 shl y)
                t = t xor (1L shl x)
            }
            states[k]++
        }
        for (k in 0 until maxPossible) {
            val check = 1 shl k
            for (state in 0 until (1 shl maxPossible)) {
                if ((state and check) != 0) {
                    states[state xor check] += states[state]
                }
            }
        }
        var bestState = 0
        for (state in 0 until (1 shl maxPossible)) {
            if (states[state] >= req && state.countOneBits() > bestState.countOneBits()) {
                bestState = state
            }
        }
        var ans = 0L
        var t = bestState
        while (t != 0) {
            val x = t.countTrailingZeroBits()
            ans = ans or (1L shl revMap[x])
            t = t xor (1 shl x)
        }
        if (ans.countOneBits() > fAnswer.countOneBits()) fAnswer = ans
    }
    print(fAnswer.toString(2).padStart(m, '0'))
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