import java.io.BufferedReader
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val s = br.readLine()
        fun solve(beg: Int, end: Int, c: Char): Int {
            if (beg + 1 == end) {
                return if (s[beg] == c) 0 else 1
            }
            val mid = (beg + end) shr 1

            var first = 0
            for (x in beg until mid) {
                if (s[x] != c) {
                    first++
                }
            }
            first += solve(mid, end, c + 1)

            var last = 0
            for (x in mid until end) {
                if (s[x] != c) {
                    last++
                }
            }
            last += solve(beg, mid, c + 1)
            return min(first, last)
        }
        sb.append(solve(0, n, 'a')).append('\n')
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