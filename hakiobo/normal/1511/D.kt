import java.io.BufferedReader

private fun gcd(p: Int, q: Int): Int {
    return if (p < 0) gcd(-p, q)
    else if (q < 0) gcd(p, -q)
    else if (p == 0) q
    else if (q == 0) p
    else if (p and 1 == 0 && q and 1 == 0) gcd(p shr 1, q shr 1) shl 1
    else if (p and 1 == 0) gcd(p shr 1, q)
    else if (q and 1 == 0) gcd(p, q shr 1)
    else if (p > q) gcd((p - q) shr 1, q)
    else gcd(p, (q - p) shr 1)
}

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val n = br.readInt()
    val k = br.readInt()
    var appended = 0

    val toMod = IntArray(k) { i ->
        gcd(i + 1, k)
    }

    fun go(cur: Int, curStep: Int, done: Array<BooleanArray>, init: Int) {
        if (appended == n) return
        for (otherStep in 1..k) {
            val i = toMod[otherStep - 1]
            if (!done[otherStep - 1][cur % i]) {
                val next = (cur + otherStep) % k
                done[otherStep - 1][cur % i] = true
                appended++
                bw.append('a' + next)
                go(next, otherStep, done, cur)
                if (appended == n) return
            }
        }
        val next = (cur + curStep) % k
        if(curStep != k) {
            appended++
            bw.append('a' + next)
            if (next != init) {
                go(next, curStep, done, init)
            }
        }
    }

    while (appended < n) {
        val done = Array(k) { i -> BooleanArray(toMod[i]) }
        bw.append('a')
        appended++
        done[k - 1][0] = true
        go(0, k, done, 0)
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