import java.io.BufferedReader
import java.util.PriorityQueue

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val k = br.readInt()
        val a = IntArray(n)
        val b = IntArray(n)
        for (i in 0 until n) {
            a[i] = br.readInt()
            b[i] = br.readInt()
        }
        if (a[0] + b[0] < k) {
            bw.appendLine("No")
        } else if (k <= a[0]) {
            bw.appendLine("Yes")
        } else {
            var minToColor = k - b.first()
            val sorted = (1 until n).sortedWith { u, v ->
                val rangeU = a[u] + b[u]
                val rangeV = a[v] + b[v]
                if (rangeV == rangeU) {
                    a[u].compareTo(a[v])
                } else {
                    rangeV.compareTo(rangeU)
                }
            }
            val pq = PriorityQueue<Int> { u, v ->
                b[v].compareTo(b[u])
            }
            var valid = false
            for (i in sorted) {
                while (a[i] + b[i] < minToColor) {
                    if (pq.isEmpty()) break else {
                        val j = pq.poll()
                        if (minToColor <= a[j]) {
                            valid = true
                            break
                        }
                        minToColor -= b[j]
                    }
                }
                if (valid) break
                if (a[i] + b[i] < minToColor) {
                    break
                } else if (minToColor <= a[i]) {
                    valid = true
                    break
                } else {
                    pq += i
                }
            }
            if (!valid) {
                while (pq.isNotEmpty()) {
                    val j = pq.poll()
                    if (minToColor <= a[j]) {
                        valid = true
                        break
                    }
                    minToColor -= b[j]
                }
            }
            if (valid) {
                bw.appendLine("yEs")
            } else {
                bw.appendLine("nO")
            }
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