import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val w = IntArray(n) { br.readInt() }.sorted()
        var maxTeams = 0
        for (targetW in 2..2 * n) {
            var low = 0
            var high = n - 1
            var numTeams = 0
            while (low < high) {
                val curW = w[low] + w[high]

                if (curW == targetW) {
                    numTeams++
                    low++
                    high--
                } else if (curW > targetW) {
                    high--
                } else {
                    low++
                }
            }
            maxTeams = maxTeams.coerceAtLeast(numTeams)
        }
        sb.append(maxTeams).append('\n')
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