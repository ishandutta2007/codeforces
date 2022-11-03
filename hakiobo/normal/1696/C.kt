import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val m = br.readInt()
        val a = IntArray(n) { br.readInt() }
        val k = br.readInt()
        val b = IntArray(k) { br.readInt() }

        val a2 = mutableListOf<Int>()
        val aCounts = mutableListOf<Long>()
        val b2 = mutableListOf<Int>()
        val bCounts = mutableListOf<Long>()
        for (i in 0 until n) {
            var num = a[i]
            var ct = 1L
            while (num % m == 0) {
                num /= m
                ct *= m
            }
            if (a2.isNotEmpty() && a2.last() == num) {
                aCounts[aCounts.lastIndex] += ct
            } else {
                a2 += num
                aCounts += ct
            }
        }
        for (i in 0 until k) {
            var num = b[i]
            var ct = 1L
            while (num % m == 0) {
                num /= m
                ct *= m
            }
            if (b2.isNotEmpty() && b2.last() == num) {
                bCounts[bCounts.lastIndex] += ct
            } else {
                b2 += num
                bCounts += ct
            }
        }
        var good = a2.size == b2.size
        if (good) {
            for (i in a2.indices) {
                if (a2[i] != b2[i]) good = false
                if (aCounts[i] != bCounts[i]) good = false
            }
        }
        if (good) {
            bw.appendLine("YES")
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