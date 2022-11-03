import java.io.BufferedReader
import kotlin.system.exitProcess

fun main() {
    val br = System.`in`.bufferedReader()
    val t = br.readInt()
    fun query(type: Int, i: Int, j: Int, x: Int): Int {
        println("? $type ${i + 1} ${j + 1} $x")
        val ret = br.readInt()
        if (ret == -1) exitProcess(0)
        return ret
    }
    repeat(t) {
        val n = br.readInt()
        var high = n
        var low = 1
        var mid = (high + low) shr 1
        while (low < high) {
            val check = query(1, 1, 0, mid)
            if (check == mid + 1) {
                low = mid + 1
            } else {
                high = check
            }
            mid = (low + high) shr 1
        }
        val perm = IntArray(n)
        perm[0] = mid
        val defaultType = if (mid * 2 > n) {
            2
        } else {
            1
        }
        for (x in 1 until n) {
            if (defaultType == 1) {
                val c = query(1, 0, x, n - 1)
                perm[x] = if (c == mid) {
                    query(2, x, 0, 1)
                } else {
                    c
                }
            } else {
                val c = query(2, x, 0, 1)
                perm[x] = if (c == mid) {
                    query(1, 0, x, n - 1)
                } else {
                    c
                }
            }
        }
        println("! ${perm.joinToString(" ")}")
        //8
        // 1 2 3 4 5 6 7 8
        //9
        // 1 2 3 4 5 6 7 8 9

    }
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