import java.io.BufferedReader
import kotlin.math.absoluteValue
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val a = IntArray(n) { br.readInt() and 1 }
        var zCount = 0
        var moveA = 0
        var moveB = 0
        for (x in 0 until n) {
            if (a[x] == 0) {
                val spotA = zCount shl 1
                val spotB = spotA + 1
                moveA += (spotA - x).absoluteValue
                moveB += (spotB - x).absoluteValue

                zCount++
            }
        }
        val ans = if (zCount shl 1 == n) {
            min(moveA, moveB)
        } else if((zCount shl 1) + 1 == n){
            moveB
        } else if((zCount shl 1) - 1 == n){
            moveA
        } else {
            -1
        }
        sb.appendLine(ans)
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