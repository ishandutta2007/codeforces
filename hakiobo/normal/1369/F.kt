import java.io.BufferedReader


fun main() {
    fun canForceWinStarting(s: Long, e: Long): Boolean {
        return if (e and 1L == 1L) {
            s and 1L == 0L
        } else if (s > e shr 1) {
            (s and 1L) == 1L
        } else if (s > e shr 2) {
            true
        } else {
            canForceWinStarting(s, e shr 2)
        }
    }

    fun canForceLoseStarting(s: Long, e: Long): Boolean {
        return canForceWinStarting(s, e shl 1)
    }

    val br = System.`in`.bufferedReader()
    val t = br.readInt()
    var canBeFirst = true
    var canBeSecond = false
    for (x in 0 until t) {
        val s = br.readLong()
        val e = br.readLong()
        val canBeSecondNext = if (canForceWinStarting(s, e)) canBeFirst else canBeSecond
        val canBeFirstNext = if (canForceLoseStarting(s, e)) canBeFirst else canBeSecond
        canBeFirst = canBeFirstNext
        canBeSecond = canBeSecondNext
    }

    print(if (canBeSecond) 1 else 0)
    print(' ')
    print(if (canBeFirst) 1 else 0)
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