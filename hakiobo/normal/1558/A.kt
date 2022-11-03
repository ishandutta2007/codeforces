import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val a = br.readInt()
        val b = br.readInt()
        val breaksPossible = BooleanArray(a + b + 1)
        var ct = 0
        var aServes = ((a + b) shr 1)
        while ((aServes shl 1) <= a + b + 1) {
            val bServes = a + b - aServes
            val (minBreak, maxBreak) = if (a >= b) {
                a - aServes to b + bServes
            } else {
                b - bServes to a + aServes
            }
            for (x in minBreak..maxBreak step 2) {
                if (!breaksPossible[x]) {
                    breaksPossible[x] = true
                    ct++
                }
            }

            aServes++
        }
        sb.appendLine(ct)
        for (x in 0..a + b) {
            if (breaksPossible[x]) {
                sb.append("$x ")
            }
        }
        sb.appendLine()
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