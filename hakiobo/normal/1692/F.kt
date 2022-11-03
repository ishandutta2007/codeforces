import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val counts = IntArray(10)
        val n = br.readInt()
        repeat(n) {
            counts[br.readInt() % 10]++
        }
        var good = false
        for (digitA in 0 until 10) {
            if (counts[digitA]-- != 0) {
                for (digitB in 0 until 10) {
                    if (counts[digitB]-- != 0) {
                        val digitC = (23 - (digitA + digitB)) % 10
                        if (counts[digitC] != 0) {
                            good = true
                        }
                    }
                    counts[digitB]++
                }
            }
            counts[digitA]++
        }
        if (good) {
            bw.appendLine("Yes")
        } else {
            bw.appendLine("no")
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