import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val (time, intervalS) = br.readLine().split(" ")
        val interval = intervalS.toInt()
        val initDigits = IntArray(4)
        var ans = 0
        initDigits[3] = time[4] - '0'
        initDigits[2] = time[3] - '0'
        initDigits[1] = time[1] - '0'
        initDigits[0] = time[0] - '0'
        val curDigits = IntArray(4) { i -> initDigits[i] }
        do {
            curDigits[3] += interval
            curDigits[2] += curDigits[3] / 10
            curDigits[3] %= 10
            curDigits[1] += curDigits[2] / 6
            curDigits[2] %= 6
            val hours = (curDigits[0] * 10 + curDigits[1]) % 24
            curDigits[0] = hours / 10
            curDigits[1] = hours % 10
            if (curDigits[0] == curDigits[3] && curDigits[1] == curDigits[2]) ans++
        } while (!curDigits.contentEquals(initDigits))
        bw.appendLine("$ans")
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