import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val nums = IntArray(n) { br.readInt() }.sorted()
        if (n and 1 == 0) {
            val mid = n shr 1
            var good = nums[0] != nums[mid]

            for (i in 1 until mid) {
                if (nums[mid + i - 1] == nums[i]) {
                    good = false
                }
            }
            if (good) {
                bw.appendLine("YES")
                for (i in 0 until mid) {
                    bw.append("${nums[i]} ${nums[mid + i]} ")
                }
                bw.newLine()
            } else {
                bw.appendLine("NO")
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