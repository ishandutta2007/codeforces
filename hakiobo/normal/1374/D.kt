import java.io.BufferedReader
import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val k = br.readInt()
        val map = TreeMap<Int, Int>()
        repeat(n) {
            val num = br.readInt()
            val rem = num % k
            if (rem != 0) {
                map[k - rem] = map.getOrDefault(k - rem, 0) + 1
            }
        }
        if (map.size == 0) {
            sb.append("0\n")
        } else {
            var most = 0L
            var remMost = -1
            for (entry in map.descendingMap()) {
                if (entry.value > most) {
                    remMost = entry.key
                    most = entry.value.toLong()
                }
            }
            sb.append((most - 1) * k + remMost + 1).append('\n')
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