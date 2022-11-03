import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readInt()
    fun comp(a: Pair<Int, Int>, b: Pair<Int, Int>): Int {
        return if (a.first == b.first) {
            a.second.compareTo(b.second)
        } else {
            a.first.compareTo(b.first)
        }
    }
    repeat(numCases) {
        val n = br.readInt()
        val nums = Array(n) { idx ->
            val num = br.readInt()
            Pair(num, idx)
        }
        val sorted = nums.sortedWith(Comparator(::comp))
        val nextInOrder = BooleanArray(n - 1){idx ->
            sorted[idx].second < sorted[idx + 1].second
        }
        var streak = 0
        var maxStreak = 0
        for(b in nextInOrder){
            if(b){
                streak++
            } else {
                streak = 0
            }
            maxStreak = maxStreak.coerceAtLeast(streak)
        }
        sb.append(n - 1 - maxStreak).append('\n')
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