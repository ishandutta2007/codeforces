import java.io.BufferedReader
import kotlin.math.absoluteValue
import kotlin.math.max
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    var first = 0
    var last = -1
    fun remove(node: Int, next: IntArray, prev: IntArray) {
        val nx = next[node]
        val pv = prev[node]
        if (nx != next.size) {
            prev[nx] = pv
        } else {
            last = pv
        }
        if (pv != -1) {
            next[pv] = nx
        } else {
            first = nx
        }
    }
    repeat(t) {
        val n = br.readInt()
        val a = LongArray(n) { br.readInt().toLong() }
        first = 0
        last = n - 1
        var good = true
        val next = IntArray(n) { i -> i + 1 }
        val prev = IntArray(n) { i -> i - 1 }
        var i = 0
        while (i != n) {
            var looping = true
            while (looping) {
                looping = false
                val pv = prev[i]
                val nx = next[i]
                if (a[i] < 0) {
                    if (pv != -1 && a[pv] <= 0) {
                        a[i] += a[pv]
                        remove(pv, next, prev)
                        looping = true
                    } else if (nx != n && a[nx] <= 0) {
                        a[i] += a[nx]
                        remove(nx, next, prev)
                        looping = true
                    }
                }
            }
            val removeMe = if (a[i] == 0L) i else -1
            i = next[i]
            if (removeMe != -1) remove(removeMe, next, prev)
        }
        i = first
        while (i != n) {
            var looping = true
            while (looping) {
                looping = false
                val pv = prev[i]
                val nx = next[i]
                if (a[i] > 0) {
                    if (nx != n && a[nx] > 0) good = false
                    if (pv != -1 && nx != n) {
                        if (-a[nx] >= a[i] && -a[pv] >= a[i]) {
                            a[i] += a[nx]
                            a[i] += a[pv]
                            remove(pv, next, prev)
                            remove(nx, next, prev)
                            if (prev[i] != -1) i = prev[i]
                            looping = true
                        }
                    }
                } else {
                    if(pv != -1 && nx != n) {
                        if(min(a[pv], a[nx]) > -a[i]) good = false
                    }
                }
            }
            i = next[i]
        }

        if (good) {
            bw.appendLine("YES")
        } else {
            bw.appendLine("NO")
        }
    }
    bw.flush()
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