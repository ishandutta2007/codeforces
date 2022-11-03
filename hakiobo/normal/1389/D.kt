import java.io.BufferedReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt().toLong()
        var k = br.readInt().toLong()
        val l1 = br.readInt().toLong()
        val r1 = br.readInt().toLong()
        val l2 = br.readInt().toLong()
        val r2 = br.readInt().toLong()
        val lowL = min(l1, l2)
        val highL = max(l1, l2)
        val lowR = min(r1, r2)
        val highR = max(r1, r2)
        if (lowR < highL) {
            var moves = 0L
            val movesToConnect = highL - lowR
            val largestEasy = highR - lowL
            var i = 0
            while (k > 0 && i < n) {
                if (k >= largestEasy) {
                    moves += movesToConnect + largestEasy
                    k -= largestEasy
                } else if (i == 0 || movesToConnect < k) {
                    moves += movesToConnect + k
                    k = 0
                } else {
                    moves += 2 * k
                    k = 0
                }
                i++
            }
            if(k != 0L){
                moves += 2 * k
            }
            sb.append(moves).append('\n')
        } else {
            val startingIntersection = (lowR - highL) * n
            val easilyExpandable = (highR - lowL) * n
            val moves = if (k <= startingIntersection) {
                0L
            } else if (k <= easilyExpandable) {
                k - startingIntersection
            } else {
                easilyExpandable - startingIntersection + 2 * (k - easilyExpandable)
            }
            sb.append(moves).append('\n')
        }
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