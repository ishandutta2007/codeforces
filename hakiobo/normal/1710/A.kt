import java.io.BufferedReader



fun main() {
    fun check(groupSize: Int, numGroups: Int, limits: LongArray) : Boolean{
        var hasOdd = numGroups and 1 == 0
        var totalGroups = 0L
        for(limit in limits) {
            val columns = limit / groupSize
            if(columns > 1) {
                totalGroups += columns
                if(columns > 2) {
                    hasOdd = true
                }
            }
        }
        return hasOdd && totalGroups >= numGroups
    }
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val m = br.readInt()
        val k = br.readInt()
        val limits = LongArray(k) { br.readInt().toLong() }
        val good = check(n, m, limits) || check(m, n, limits)
        if(good) {
            bw.appendLine("yes")
        } else {
            bw.appendLine("no")
        }
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