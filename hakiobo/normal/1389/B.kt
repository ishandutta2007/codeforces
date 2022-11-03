import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val k = br.readInt()
        var z = br.readInt()
        val a = IntArray(n) { br.readInt() }
        val pt = k - 2 * z
        var best = 0
        var score = a.first()

        if (pt >= 2) {
            for (x in 1..pt) {
                score += a[x]
            }
            for (x in 1..pt) {
                best = best.coerceAtLeast(score + z * (a[x] + a[x - 1]))
            }
            for (x in (pt + 1)..k) {
                val dif = x - pt
                score += a[x]
                best = if (dif and 1 == 0) {
                    best.coerceAtLeast(score + z * (a[x] + a[x - 1]))
                } else {
                    z--
                    best.coerceAtLeast(score + a[x - 1] + z * (a[x] + a[x - 1]))
                }
            }
        } else {
            var movesLeft = k
            for (x in 1..k) {
                score += a[x]
                movesLeft--
                best = if (movesLeft and 1 == 0) {
                    best.coerceAtLeast(score + (movesLeft / 2) * (a[x - 1] + a[x]))
                } else {
                    best.coerceAtLeast(score + a[x - 1] + (movesLeft / 2) * (a[x - 1] + a[x]))
                }
            }
        }
        sb.append(best).append('\n')
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