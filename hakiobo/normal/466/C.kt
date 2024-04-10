import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    var sum = 0L
    val nums = IntArray(n) {
        val num = br.readInt()
        sum += num
        num
    }
    var p = 0L
    var ct1 = 0L
    var ct2 = 0L
    for (x in 0 until n) {
        p += nums[x]
        if (x != n - 1 && p * 3 == sum * 2) {
            ct2 += ct1
        }
        if (p * 3 == sum) {
            ct1++
        }
    }
    print(ct2)
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