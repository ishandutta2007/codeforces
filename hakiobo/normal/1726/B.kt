import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val m = br.readInt()
        if (m < n) {
            bw.appendLine("no")
        } else if (n and 1 == 0) {
            if (m and 1 == 1) {
                bw.appendLine("no")
            } else {
                bw.appendLine("yes")
                val extra = (m - (n - 2)) shr 1
                repeat(n - 2) {
                    bw.append("1 ")
                }
                bw.appendLine("$extra $extra")
            }
        } else {
            bw.appendLine("yes")
            val extra = m - (n - 1)
            repeat(n - 1) {
                bw.append("1 ")
            }
            bw.appendLine("$extra")
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