import java.io.BufferedReader
import java.util.TreeSet

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val m = br.readInt()
        val a = IntArray(n) { br.readInt() }
        val nums = TreeSet<Int>()
        var minSoFar = Int.MAX_VALUE
        for (i in 0 until n) {
            if (a[i] < minSoFar) {
                nums += i
                minSoFar = a[i]
            }
        }
        repeat(m) {
            val k = br.readInt() - 1
            val d = br.readInt()
            a[k] -= d
            var c = nums.ceiling(k + 1)
            while (c != null && a[c] >= a[k]) {
                nums.remove(c)
                c = nums.ceiling(k + 1)
            }
            val fl = nums.floor(k)
            if (fl != null && a[fl] > a[k]) {
                nums += k
            }
            bw.append("${nums.size} ")
        }
        bw.newLine()
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