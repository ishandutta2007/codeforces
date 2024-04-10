import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val a = IntArray(n) { br.readInt() - 1 }
    val lastOccurrence = IntArray(n)
    for (idx in 0 until n) {
        lastOccurrence[a[idx]] = idx
    }
    var furthestOut = -1
    var ans = 0

    for (start in 0 until n) {
        if (start <= furthestOut) continue
        var curLast = lastOccurrence[a[start]]
        var curStart = start
        furthestOut = start
        if (curLast - curStart >= 2) {
            while (curLast > furthestOut) {
                ans += (curLast - furthestOut + 1) - 2
                furthestOut = curLast
                var newLast = curLast
                var newStart = curStart
                for (x in curStart + 1 until curLast) {
                    if (lastOccurrence[a[x]] > newLast) {
                        newLast = lastOccurrence[a[x]]
                        newStart = x
                    }
                }
                curStart = newStart
                curLast = newLast
            }
        }
    }


    println(ans)
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