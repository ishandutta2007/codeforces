import java.io.BufferedReader
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val n = br.readInt()
    val q = br.readInt()
    val a = IntArray(n) { br.readInt() }
    val nextReachable = Array(n) { IntArray(19) { n } }
    val latest = IntArray(19) { n }
    for (x in n - 1 downTo 0) {
        var s = a[x]
        while (s > 0) {
            val bit = s.countTrailingZeroBits()
            nextReachable[x][bit] = x
            if (latest[bit] != n) {
                for (y in 0 until 19) {
                    nextReachable[x][y] = min(nextReachable[x][y], nextReachable[latest[bit]][y])
                }
            }
            latest[bit] = x
            s = s xor (1 shl bit)
        }
    }
    repeat(q) {
        val x = br.readInt() - 1
        val y = br.readInt() - 1
        val ay = a[y]
        if(ay != 0 && nextReachable[x][ay.countTrailingZeroBits()] <= y){
            sb.appendLine("Shi")
        } else {
            sb.appendLine("Fou")
        }
    }
    println(sb)
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