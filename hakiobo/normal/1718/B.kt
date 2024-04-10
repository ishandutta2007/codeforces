import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    val limit = 54
    val fibo = LongArray(limit)
    val fiboPrefix = LongArray(limit)
    fibo[1] = 1
    fiboPrefix[1] = 1
    for (i in 2 until limit) {
        fibo[i] = fibo[i - 1] + fibo[i - 2]
        fiboPrefix[i] = fiboPrefix[i - 1] + fibo[i]
    }


    val t = br.readInt()
    fun r(counts: LongArray, fiboNum: Int, lastNum: Int): Boolean {
        if (fiboNum == 0) return true
        for (i in counts.indices) {
            if (i != lastNum && counts[i] >= fibo[fiboNum]) {
                counts[i] -= fibo[fiboNum]
                val ret = r(counts, fiboNum - 1, i)
                counts[i] += fibo[fiboNum]
                if (ret) return true
            }
        }
        return false
    }
    repeat(t) {
        val k = br.readInt()
        val counts = LongArray(k) { br.readInt().toLong() }
        val sum = counts.sum()
        var high = limit
        var low = 0
        while (low < high) {
            val mid = (low + high) shr 1
            if (fiboPrefix[mid] < sum) {
                low = mid + 1
            } else {
                high = mid
            }
        }
        if (sum == fiboPrefix[low]) {
            if (r(counts, low, -1)) {
                bw.appendLine("yes")
            } else {
                bw.appendLine("no")
            }
        } else {
            bw.appendLine("NO")
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