import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val l = br.readInt()
        val r = br.readInt()
        val k = br.readInt()
        if (r == l) {
            if(l == 1){
                sb.appendLine("NO")
            } else {
                sb.appendLine("YES")
            }
        } else {
            val kNeeded = if (l and 1 == 0) {
                (r - l + 1) shr 1
            } else {
                (r - l + 2) shr 1
            }
            if (k >= kNeeded) sb.appendLine("YES") else sb.appendLine("NO")
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