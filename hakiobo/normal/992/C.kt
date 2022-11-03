import java.io.BufferedReader

fun main() {
    fun modPow(n: Long, k: Long, m: Long): Long {
        if (k == 0L) {
            return 1L
        }
        var half = modPow(n, k shr 1, m)
        half *= half
        if (k and 1L == 1L) {
            half %= m
            half *= n
        }
        return half % m
    }

    val br = System.`in`.bufferedReader()
    val mod = 1_000_000_007L

    val x = br.readLong()
    val k = br.readLong()
    if (x == 0L) {
        print(0)
    } else {
        val tp = modPow(2L, k, mod)
        val base = ((x % mod) * tp * 2) % mod
        print((base - tp + 1 + mod) % mod)
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

private fun BufferedReader.readLong(): Long {
    var ret = read().toLong()
    while (ret <= SPACE_INT) {
        ret = read().toLong()
    }
    val neg = ret == '-'.toLong()
    if (neg) {
        ret = read().toLong()
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