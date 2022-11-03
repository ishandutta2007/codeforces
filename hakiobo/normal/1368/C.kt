import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val sb = StringBuilder()
    fun addPoint(x: Int, y: Int) {
        sb.append(x).append(' ').append(y).append('\n')
    }
    addPoint(-1, -1)
    addPoint(-1, 0)
    addPoint(0, -1)
    addPoint(0, 0)
    for (x in 1..n) {
        addPoint(x, x)
        addPoint(x - 1, x)
        addPoint(x, x - 1)
    }
    println(4 + 3 * n)
    print(sb)
}

private const val SPACE_INT = ' '.toInt()
private const val ZERO_INT = '0'.toInt()
private const val NL_INT = '\n'.toInt()

@Suppress("DuplicatedCode")
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