import java.io.BufferedReader
import java.util.PriorityQueue

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val slices = LongArray(n) { br.readInt().toLong() }
        val sorted = slices.sorted()
        val otherSlices = PriorityQueue<Long> { a, b -> b.compareTo(a) }
        otherSlices += slices.sum()
        var idx = n - 1
        while (idx >= 0 && otherSlices.peek() >= sorted[idx]) {
            val num = otherSlices.poll()
            if(num == sorted[idx]) {
                idx--
            } else {
                otherSlices += num shr 1
                otherSlices += (num + 1) shr 1
            }
        }
        if(idx >= 0) {
            bw.append("NO\n")
        } else {
            bw.append("YES\n")
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