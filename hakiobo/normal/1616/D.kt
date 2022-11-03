import java.io.BufferedReader
import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val a = LongArray(n) { br.readInt().toLong() }
        val x = br.readInt().toLong()
        for (i in 0 until n) {
            a[i] -= x
        }
        if (n < 3) {
            if (n == 2 && a.sum() >= 0) {
                sb.appendLine(2)
            } else {
                sb.appendLine(1)
            }
        } else {
            val good2 = BooleanArray(n)
            val good3 = BooleanArray(n)
            var sum2 = a[0] + a[1]
            var sum3 = a[0] + a[1] + a[2]
            for (i in 0 until n - 1) {
                good2[i] = sum2 >= 0
                if (i != 0) {
                    good3[i - 1] = sum3 >= 0 && good2[i - 1] && good2[i]
                }

                if (i + 2 < n) {
                    sum2 += a[i + 2] - a[i]
                    if (i != 0) {
                        sum3 += a[i + 2] - a[i - 1]
                    }
                }
            }
            var ans = 0
            var start = 0
            while (start < n) {
                if (good3[start]) {
                    ans += 3
                    start++
                    while (start < n && good3[start]) {
                        ans++
                        start++
                    }
                    start += 3
                } else if (good2[start]) {
                    ans += 2
                    start += 3
                } else {
                    ans++
                    start += 2
                }
            }
            sb.appendLine(ans)
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