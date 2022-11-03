import java.io.BufferedReader
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val needs = IntArray(n) { br.readInt() }
        val caps = IntArray(n) { br.readInt() }
        val leftAssign = IntArray(n)
        for (x in 0 until n) {
            val upper = (x + 1) % n
            leftAssign[x] = min(needs[x], caps[x])
            needs[x] -= leftAssign[x]
            caps[x] -= leftAssign[x]
            val rAssign = min(needs[upper], caps[x])
            needs[upper] -= rAssign
            caps[x] -= rAssign
        }
        var good = true
        for (x in 0 until n) {
            val lower = (x + n - 1) % n
            if (caps[lower] != 0) {
                val free = min(needs[x], caps[lower])
                caps[lower] -= free
                needs[x] -= free
                val shift = min(caps[lower], leftAssign[x])
                caps[lower] -= shift
                caps[x] += shift
                leftAssign[x] -= shift
            }
            if (needs[x] != 0) {
                good = false
                break
            }
        }
        sb.append(if (good) "YES\n" else "NO\n")
    }
    print(sb)
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