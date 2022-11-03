import java.io.BufferedReader

fun main() {
    fun gcd(p: Int, q: Int): Int {
        return if (p == 0) q
        else if (q == 0) p
        else if (p and 1 == 0 && q and 1 == 0) gcd(p shr 1, q shr 1) shl 1
        else if (p and 1 == 0) gcd(p shr 1, q)
        else if (q and 1 == 0) gcd(p, q shr 1)
        else if (p > q) gcd((p - q) shr 1, q)
        else gcd(p, (q - p) shr 1)
    }

    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val a = IntArray(n) { br.readInt() }
        var minIdx = 0
        for (x in 1 until n) {
            if (a[x] < a[minIdx]) {
                minIdx = x
            }
        }
        if (minIdx != 0) {
            a[0] = a[minIdx]
            sb.append("$n\n1 ${minIdx + 1} ${a[minIdx]} ${a[minIdx]}\n")
        } else {
            sb.append("${n - 1}\n")
        }
        for (x in 1 until n) {
            sb.append("1 ${x + 1} ${a[0]} ${a[0] + x}\n")
        }
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