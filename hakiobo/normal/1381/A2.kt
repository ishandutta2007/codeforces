import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val a = br.readLine()
        val b = br.readLine()
        val moves = StringBuilder()
        var numMoves = 0
        for (x in 0 until n) {
            val check = if (x and 1 == 0) {
                x shr 1
            } else {
                n - 1 - (x shr 1)
            }

            if ((b[n - x - 1] == a[check]) == (x and 1 == 0)) {
                moves.append(1).append(' ')
                numMoves++
            }
            moves.append(n - x).append(' ')
            numMoves++
        }
        sb.append(numMoves).append(' ').append(moves).append('\n')
    }

    print(sb)
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