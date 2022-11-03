import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val k = br.readInt()
        val nums = IntArray(n) { br.readInt() }
        var badCt = 0
        var ans = 0
        for (i in 0 until k) {
            if (nums[i] >= nums[i + 1] * 2) badCt++
        }
        if (badCt == 0) ans++

        for (end in k + 1 until n) {
            if (nums[end - 1] >= nums[end] * 2) badCt++
            if (nums[end - k - 1] >= nums[end - k] * 2) badCt--
            if (badCt == 0) ans++
        }
        bw.appendLine("$ans")
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