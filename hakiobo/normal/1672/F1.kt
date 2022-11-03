import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val a = IntArray(n) { br.readInt() - 1 }
        val byCount = Array(n) { mutableListOf<Int>() }
        val counts = IntArray(n)
        for (i in 0 until n) {
            byCount[counts[a[i]]++].add(i)
        }
        val b = IntArray(n)
        for (ct in 0 until n) {
            val indices = byCount[ct]
            if (indices.isEmpty()) break
            indices.sortWith { i, j ->
                val iNum = a[i]
                val jNum = a[j]
                if (counts[iNum] == counts[jNum]) {
                    iNum.compareTo(jNum)
                } else {
                    counts[jNum].compareTo(counts[iNum])
                }
            }
            for (i in 1 until byCount[ct].size) {
                b[byCount[ct][i - 1]] = a[byCount[ct][i]] + 1
            }
            b[byCount[ct][byCount[ct].lastIndex]] = a[byCount[ct][0]] + 1
        }
        bw.appendLine(b.joinToString(" "))
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