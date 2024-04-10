import java.io.BufferedReader
import java.util.TreeSet

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val sets = Array(2) { TreeSet<Int>() }
        var cur = 0
        repeat(n) {
            sets[cur].add(br.readInt())
        }
        var expectedSize = n
        repeat(n - 1) {
            var prev = -1
            if (sets[cur].size != expectedSize) {
                sets[cur xor 1].add(0)
            }
            for (num in sets[cur]) {
                if (prev != -1) {
                    sets[cur xor 1].add(num - prev)
                }
                prev = num
            }
            sets[cur].clear()
            expectedSize--
            cur = cur xor 1
        }

        bw.appendLine("${sets[cur].first()}")

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