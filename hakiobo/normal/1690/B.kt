import java.io.BufferedReader
import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val a = IntArray(n) { br.readInt() }
        val b = IntArray(n) { br.readInt() }
        var minMoves = 0
        var exact = false
        var good = true
        for (i in 0 until n) {
            if (b[i] == 0) {
                if (a[i] > minMoves) {
                    if(exact) {
                        good = false
                    } else {
                        minMoves = a[i]
                    }
                }
            } else {
                val dif = a[i] - b[i]
                if(dif < minMoves) {
                    good = false
                } else if(!exact) {
                    minMoves = dif
                    exact = true
                } else if(dif != minMoves) {
                    good = false
                }
            }
        }
        if(good) {
            bw.appendLine("YES")
        } else {
            bw.appendLine("NO")
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