import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val a = br.readLine()
    val b = br.readLine()


    var streak = 0
    var posStreak = 0
    var negStreak = 0
    var highest = 0
    for (x in 0 until n) {
        if (a[x] == '1' && b[x] == '0') {
            posStreak = (posStreak - 1).coerceAtLeast(0)
            negStreak++
            streak++
            highest = highest.coerceAtLeast(negStreak)
        } else if (a[x] == '0' && b[x] == '1') {
            posStreak++
            negStreak = (negStreak - 1).coerceAtLeast(0)
            streak--
            highest = highest.coerceAtLeast(posStreak)
        }
    }
    print(if (streak == 0) highest else -1)
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