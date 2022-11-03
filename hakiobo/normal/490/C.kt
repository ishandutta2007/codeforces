import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val num = br.readLine()
    val n = num.length
    val (a, b) = br.readLine().split(" ").map { it.toLong() }
    val lefts = LongArray(n)
    val rights = LongArray(n)
    lefts[0] = (num.first() - '0') % a
    for(i in 1 until n) {
        lefts[i] = (lefts[i - 1] * 10 + (num[i] - '0')) % a
    }
    var shift = 10L
    rights[n - 1] = (num.last() - '0') % b
    for(i in n - 2 downTo 0) {
        rights[i] = (rights[i + 1] + shift * (num[i] - '0')) % b
        shift *= 10
        shift %= b
    }
    for(i in 1 until n ) {
        if(num[i] != '0' && lefts[i - 1] % a == 0L && rights[i] % b == 0L) {
            bw.append("YES\n")
            bw.appendLine(num.subSequence(0, i))
            bw.appendLine(num.substring(i))
            bw.flush()
            return
        }
    }
    bw.appendLine("NO")
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