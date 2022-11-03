import java.io.BufferedReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    val n = br.readInt()
    val maybeSick = BooleanArray(n) { true }
    val next = IntArray(n) { idx -> idx + 1 }
    val prev = IntArray(n) { idx -> idx - 1 }

    val segTree = HowToEvenUseASegTree2(n)
    val q = br.readInt()
    repeat(q) {
        val type = br.readInt()
        if (type == 0) {
            val l = br.readInt() - 1
            val r = br.readInt() - 1
            val x = br.readInt()
            if (x == 0) {
                var cur = l
                while (cur <= r && !maybeSick[cur]) {
                    val nx = next[cur]
                    next[cur] = max(nx, next[r])
                    cur = nx
                }
                while (cur <= r) {
                    maybeSick[cur] = false
                    if (prev[cur] != -1) {
                        next[prev[cur]] = next[cur]
                    }
                    if (next[cur] != n) {
                        prev[next[cur]] = prev[cur]
                    }
                    val nx = next[cur]
                    next[cur] = max(next[cur], next[r])
                    cur = nx
                }
            } else {
                segTree.setRightMin(l, r)
            }
        } else {
            val person = br.readInt() - 1
            if (maybeSick[person]) {
                val left = prev[person] + 1
                val right = next[person] - 1
                if (segTree.getMinRight(left, right) <= right) {
                    bw.appendLine("YES")
                } else {
                    bw.appendLine("N/A")
                }
            } else {
                bw.appendLine("NO")
            }
        }
    }

    bw.flush()
}

private class HowToEvenUseASegTree2(private val n: Int) {
    private val minRights = IntArray(n shl 1) { n } // stores right edge of active zones

    fun setRightMin(index: Int, value: Int) {
        var cur = index + n
        while (cur != 0 && value < minRights[cur]) {
            minRights[cur] = value
            cur = cur shr 1
        }
    }


    fun getMinRight(begin: Int, end: Int): Int {
        var left = begin + n
        var right = end + n
        var ans = n
        while (left <= right) {
            if (left and 1 == 1) ans = min(ans, minRights[left++])
            if (right and 1 == 0) ans = min(ans, minRights[right--])
            left = left shr 1
            right = right shr 1
        }
        return ans
    }
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