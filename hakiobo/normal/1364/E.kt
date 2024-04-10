import java.io.BufferedReader
import kotlin.math.max
import kotlin.system.exitProcess

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val savedQueries = Array(n) { IntArray(n) }
    fun query(a: Int, b: Int): Int {
        if (savedQueries[a][b] != 0) return savedQueries[a][b]
        println("? %d %d".format(a + 1, b + 1))
        val res = br.readInt()
        savedQueries[a][b] = res
        savedQueries[b][a] = res
        if (res == -1) {
            exitProcess(-1)
        }
        return res
    }

    val notZero = BooleanArray(n)
    val focusNums = IntArray(3) { it }
    fun checkZeros() {
        val a = focusNums[0]
        val b = focusNums[1]
        val c = focusNums[2]
        val ab = query(a, b)
        val bc = query(b, c)
        if (ab == bc) {
            notZero[b] = true
        } else if (ab > bc) {
            notZero[a] = true
        } else {
            notZero[c] = true
        }
    }

    var ptr = 3
    while (ptr <= n) {
        checkZeros()
        for (i in 0 until 3) {
            if (notZero[focusNums[i]]) {
                focusNums[i] = ptr++
            }
        }
    }
    val zeroIndex = if (ptr == n + 1) {
        var a = -1
        var b = -1
        for (i in 0 until 3) {
            if (focusNums[i] == n) {
                a = focusNums[(i + 1) % 3]
                b = focusNums[(i + 2) % 3]
            }
        }
        val zero: Int
        var other = 0
        while (true) {
            if (other != a && other != b) {
                val aq = query(a, other)
                val bq = query(b, other)
                if (aq != bq) {
                    zero = if (aq < bq) a else b
                    break
                }
            }
            other++
        }
        zero
    } else {
        focusNums.min()!!
    }

    val vals = IntArray(n) { idx ->
        if (idx != zeroIndex) {
            query(zeroIndex, idx)
        } else {
            0
        }
    }
    println("! %s".format(vals.joinToString(" ")))
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