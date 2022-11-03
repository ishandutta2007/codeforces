import java.io.BufferedReader

fun main() {
    val mod = 1_000_000_007L
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val x = br.readInt()
    val y = br.readInt()
    val n = br.readInt() % 6
    val xMod = ((x % mod) + mod) % mod
    val yMod = ((y % mod) + mod) % mod
    val difMod = (((y - x) % mod) + mod) % mod

    when (n) {
        1 -> {
            println(xMod)
        }
        2 -> println(yMod)
        3 -> println(difMod)
        4 -> println((mod - xMod) % mod)
        5 -> println((mod - yMod) % mod)
        0 -> println((mod - difMod) % mod)
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