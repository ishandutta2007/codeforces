import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val n = br.readInt()
    val m = br.readInt()
    val a = LongArray(n) { br.readLong() }
    val b = LongArray(m) { br.readLong() }
    var g = 0L
    for (i in 1 until n) {
        g = gcd(a[0] - a[i], g)
    }

    for (i in 0 until m) {
        val ans = gcd(g, a[0] + b[i])
        bw.append("$ans ")
    }
    bw.flush()
}

private fun gcd(p: Long, q: Long): Long {
    return if (p < 0) gcd(-p, q)
    else if (q < 0) gcd(p, -q)
    else if (p == 0L) q
    else if (q == 0L) p
    else if (p and 1L == 0L && q and 1L == 0L) gcd(p shr 1, q shr 1) shl 1
    else if (p and 1L == 0L) gcd(p shr 1, q)
    else if (q and 1L == 0L) gcd(p, q shr 1)
    else if (p > q) gcd((p - q) shr 1, q)
    else gcd(p, (q - p) shr 1)
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