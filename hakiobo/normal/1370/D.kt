import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val k = br.readInt()
    val nums = IntArray(n) { br.readInt() }
    val sorted = nums.sorted()
    fun check(threshold: Int, odd: Boolean): Boolean {
        var takeNext = odd
        var cnt = 0
        for (i in 0 until n) {
            if (!takeNext) {
                cnt++
                takeNext = true
            } else if (nums[i] <= threshold) {
                cnt++
                takeNext = false
            }
            if(cnt == k) return true
        }
        return false
    }

    var low = 0
    var high = n - 1
    var mid = (low + high) shr 1
    while (low != high) {
        if (check(sorted[mid], true) || check(sorted[mid], false)) {
            high = mid
        } else {
            low = mid + 1
        }
        mid = (low + high) shr 1
    }
    print(sorted[mid])
}

private const val SPACE_INT = ' '.toInt()
private const val ZERO_INT = '0'.toInt()
private const val NL_INT = '\n'.toInt()

@Suppress("DuplicatedCode")
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