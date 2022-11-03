import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val n = br.readInt()
    if (n and 1 == 1) {
        println("YES")
        val ans = IntArray(n shl 1)
        for (x in 0 until n) {
            val low = (x shl 1) + 1
            val high = (x + 1) shl 1
            if (x and 1 == 0) {
                ans[x] = low
                ans[x + n] = high
            } else {
                ans[x + n] = low
                ans[x] = high
            }
        }
        println(ans.joinToString(" "))
    } else {
        print("NO")
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