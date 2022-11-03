import java.io.BufferedReader
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readInt()
    repeat(numCases){
        val n = br.readInt()
        val m = br.readInt()
        val zCounts = IntArray(n + m - 1)
        val oCounts = IntArray(n + m - 1)
        repeat(n){ row ->
            repeat(m){ col ->
                if(br.readInt() == 0){
                    zCounts[row + col]++
                } else {
                    oCounts[row + col]++
                }
            }
        }
        var cost = 0
        for(x in 0 until (zCounts.size shr 1)){
            cost += min(zCounts[x] + zCounts[m + n - 2 - x], oCounts[x] + oCounts[m + n - 2 - x])
        }
        sb.append(cost).append('\n')
    }

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
    while (read <= SPACE_INT && read != -1) {
        mark(1)
        read = read()
        if (read == NL_INT) {
            read = -1
            break
        }
    }
    if (read != -1) {
        reset()
    }
    return if (neg) -ret else ret
}