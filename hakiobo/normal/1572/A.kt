import java.io.BufferedReader
import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        var toRead = PriorityQueue<Int>()

        val neededFor = Array(n) { mutableListOf<Int>() }
        val ct = IntArray(n) { chap ->
            val k = br.readInt()
            repeat(k) {
                val req = br.readInt() - 1
                neededFor[req].add(chap)
            }
            if (k == 0) toRead.add(chap)
            k
        }
        var next = PriorityQueue<Int>()
        var read = 0
        var ans = 0
        while (toRead.isNotEmpty()) {
            ans++
            while (toRead.isNotEmpty()) {
                val chap = toRead.poll()
                read++
                for (needed in neededFor[chap]) {
                    ct[needed]--
                    if (ct[needed] == 0) {
                        if (needed > chap) {
                            toRead.add(needed)
                        } else {
                            next.add(needed)
                        }
                    }
                }
            }
            val temp = toRead
            toRead = next
            next = temp
        }
        if (read == n) {
            sb.appendLine(ans)
        } else {
            sb.appendLine(-1)
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