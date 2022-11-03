import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readInt()
    fun gcd(p: Int, q: Int): Int {
        return if (p == 0) q
        else if (q == 0) p
        else if (p and 1 == 0 && q and 1 == 0) gcd(p shr 1, q shr 1) shl 1
        else if (p and 1 == 0) gcd(p shr 1, q)
        else if (q and 1 == 0) gcd(p, q shr 1)
        else if (p > q) gcd((p - q) shr 1, q)
        else gcd(p, (q - p) shr 1)
    }
    repeat(numCases) {
        val n = br.readInt()
        val k = br.readInt()
        val cts = IntArray(26)
        val s = br.readLine()
        var max = 0
        for (c in s) {
            max = max.coerceAtLeast(++cts[c - 'a'])
        }
        for (a in n downTo max + 1) {
            val f = gcd(k, a)
            if (f == 1) {
                continue
            } else {
                val g = a / f
                var sum = 0
                for(ct in cts){
                    sum += ct / g
                }
                if (sum >= f) {
                    max = a
                    break
                }
            }
        }
        sb.append(max).append('\n')
    }
    print(sb)
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