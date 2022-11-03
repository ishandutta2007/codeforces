import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val n = br.readInt()
//    val heights = LongArray(n) { br.readLong() }
    val nonIncreaseStack = IntArray(n)
    var sp = 0
    var low = br.readLong()
//    var high = low
    // high = low + (x - 1 - sp)
    for (x in 1 until n) {
        var new = br.readLong()
//        val dif = new - (low + (x - 1 - sp))
        while ((low + (x - 1 - sp)) + 2 <= new && sp != 0) {
            val top = nonIncreaseStack[sp - 1]
            val dif = new - (low + (x - 1 - sp))
            if (dif > x - top) {
                new -= (x - top)
                sp--
            } else {
                new -= (dif - 1)
                nonIncreaseStack[sp - 1] += (dif - 1).toInt()
            }
        }
        if ((low + (x - 1 - sp)) + 2 <= new) {
            val dif = new - (low + (x - 1 - sp))
            low += (dif - 1) / (x + 1)
            if ((dif - 1) % (x + 1) != 0L) {
                low++
                nonIncreaseStack[sp++] = ((dif - 1) % (x + 1)).toInt()
            }
        } else if (low + (x - 1 - sp) == new){
            nonIncreaseStack[sp++] = x
        }

    }

    var idx = 0
    for (x in 0 until n) {
        if (idx < sp && nonIncreaseStack[idx] == x) {
            idx++
        }
        sb.append(low + x - idx).append(" ")
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