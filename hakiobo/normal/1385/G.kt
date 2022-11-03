import java.io.BufferedReader
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val cts = IntArray(n)
        val locations = IntArray(n)
        val other = IntArray(2 * n)
        var good = true
        repeat(2) { row ->
            repeat(n) { col ->
                val num = br.readInt() - 1
                val thisLoc = (col shl 1) or row
                when (cts[num]) {
                    0 -> {
                        locations[num] = thisLoc
                    }
                    1 -> {
                        other[thisLoc] = locations[num]
                        other[locations[num]] = thisLoc
                    }
                    else -> good = false
                }
                cts[num]++
            }
        }
        if (good) {
            val movesSb = StringBuilder()
            var numMoves = 0
            val processed = BooleanArray(n)
            for (x in 0 until n) {
                if (processed[x]) continue
                val aSb = StringBuilder()
                val bSb = StringBuilder()
                processed[x] = true
                var columnsUsed = 1
                var next = other[(x shl 1) + 1]
                var moves = 0
                bSb.append(x + 1).append(' ')
                while (next != x shl 1) {
                    processed[next shr 1] = true
                    columnsUsed++
                    if (next and 1 == 0) {
                        bSb.append((next shr 1) + 1).append(' ')
                    } else {
                        moves++
                        aSb.append((next shr 1) + 1).append(' ')
                    }
                    next = other[next xor 1]
                }
                if (moves < columnsUsed - moves) {
                    numMoves += moves
                    movesSb.append(aSb)
                } else {
                    numMoves += columnsUsed - moves
                    movesSb.append(bSb)
                }
            }
            sb.append(numMoves).append('\n')
            sb.append(movesSb).append('\n')
        } else {
            sb.append("-1\n")
        }
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