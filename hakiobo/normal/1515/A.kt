import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val x = br.readInt()
        val nums = MutableList(n) { br.readInt() }
        nums.sort()
        var cur = 0
        var idx = 0

        while (idx < n) {
            if (cur + nums[idx] != x) {
                cur += nums[idx]
                idx++
            } else if (idx != n - 1) {
                val tmp = nums[idx]
                nums[idx] = nums[idx + 1]
                nums[idx + 1] = tmp
                idx += 2
            } else {
                idx += 2
            }
        }
        if (idx == n + 1) {
            sb.append("NO\n")
        } else {
            sb.append("YES\n").append(nums.joinToString(" ")).append("\n")
        }
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