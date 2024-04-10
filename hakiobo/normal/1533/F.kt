import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val s = br.readLine()
    val prefixCount = IntArray(s.length + 1)
    for (x in 1..s.length) {
        prefixCount[x] = prefixCount[x - 1]
        if (s[x - 1] == '0') prefixCount[x]++
    }
    fun countZeros(start: Int, end: Int): Int {
        return prefixCount[end + 1] - prefixCount[start]
    }

    fun countOnes(start: Int, end: Int): Int {
        return end - start + 1 - countZeros(start, end)
    }
    for (k in 1..s.length) {
        var start = 0
        var ans = 0
        while (start < s.length) {
            ans++
            var low = start + k * 2
            var high = s.length
            while (low < high) {
                val mid = (low + high) shr 1
                if (countOnes(start, mid) <= k || countZeros(start, mid) <= k) {
                    low = mid + 1
                } else {
                    high = mid
                }
            }
            start = high
        }
        sb.append(ans).append(" ")
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