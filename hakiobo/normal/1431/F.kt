import java.io.BufferedReader
import java.util.*
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val k = br.readInt()
    val x = br.readInt()
    val nums = LongArray(n) { br.readInt().toLong() }
    fun isGood(metric: Long): Boolean {
        val pQueue = PriorityQueue<Long>()
        var moves = 0
        var idx = 0
        while (idx != n) {
            var sum = 0L
            for (i in idx until min(idx + x, n)) {
                pQueue += -nums[i]
                sum += nums[i]
            }
            idx = min(idx + x, n)
            while (sum > metric) {
                moves++
                sum += pQueue.poll()
                if (idx != n) {
                    pQueue += -nums[idx]
                    sum += nums[idx]
                    idx++
                }
            }
            pQueue.clear()
        }
        return moves <= k
    }
    var low = 0L
    var high = nums.sum() + 1
    var mid = (low + high) shr 1
    while (low != high){
        if(isGood(mid)){
            high = mid
        } else {
            low = mid + 1
        }
        mid = (low + high) shr 1
    }
    print(mid)
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