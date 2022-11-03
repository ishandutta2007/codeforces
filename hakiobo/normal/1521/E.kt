import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    fun getSpotsA(n: Int) = n * ((n + 1) shr 1)
    fun getSpotsB(n: Int) = ((n + 1) shr 1) * (n shr 1)
    repeat(t) {
        val m = br.readInt()
        val k = br.readInt()
        val a = IntArray(k) { br.readInt() }.withIndex().sortedByDescending { it.value }

        var n = 1
        while (m > getSpotsA(n) + getSpotsB(n) || a.first().value > getSpotsA(n)) {
            n++
        }
        val ans = Array(n) { IntArray(n) }
        var i = 0
        var j = 0

        fun fill(r: Int, c: Int) {
            var row = r
            var col = c
            while (row < n && i < k && col < n) {
                if (j == a[i].value) {
                    i++
                    j = 0
                } else {
                    ans[row][col] = a[i].index + 1
                    j++
                    col += 2
                    if (col >= n) {
                        row += 2
                        col = c
                    }
                }
            }
        }
        fill(0, 1)
        fill(0, 0)
        fill(1, 0)

        sb.append(n).append("\n").append(ans.joinToString("\n") { it.joinToString(" ") }).append("\n")
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