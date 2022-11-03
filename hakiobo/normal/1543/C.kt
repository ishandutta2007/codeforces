import java.io.BufferedReader

fun main() {
    val epsilon = 1E-11
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readLine().toInt()
    repeat(t) {
        val (c, m, p, v) = br.readLine().split(" ").map { it.toDouble() }
        fun solve(c: Double?, m: Double?, p: Double, v: Double): Double {
            var ans = 1.0
            if (c != null) {
                ans += if (m == null) {
                    if (c - epsilon > v) {
                        c * solve(c - v, null, p + v, v)
                    } else {
                        c * solve(null, null, p + c, v)
                    }
                } else {
                    if (c - epsilon > v) {
                        c * solve(c - v, m + v / 2, p + v / 2, v)
                    } else {
                        c * solve(null, m + c / 2, p + c / 2, v)
                    }
                }
            }
            if (m != null) {
                ans += if (c == null) {
                    if (m - epsilon > v) {
                        m * solve(null, m - v, p + v, v)
                    } else {
                        m * solve(null, null, p + m, v)
                    }
                } else {
                    if (m - epsilon > v) {
                        m * solve(c + v / 2, m - v, p + v / 2, v)
                    } else {
                        m * solve(c + m / 2, null, p + m / 2, v)
                    }
                }
            }
            return ans
        }
        sb.appendLine(solve(c, m, p, v))
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