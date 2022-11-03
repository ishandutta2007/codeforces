import java.io.BufferedReader
import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val n = br.readInt()
    val k = br.readInt()
    val aLikes = PriorityQueue<Int>()
    val bLikes = PriorityQueue<Int>()
    val bothLike = PriorityQueue<Int>()
    repeat(n) {
        val time = br.readInt()
        val aLike = br.readInt() == 1
        val bLike = br.readInt() == 1
        if (aLike && bLike) {
            bothLike += time
        } else if (aLike) {
            aLikes += time
        } else if (bLike) {
            bLikes += time
        }
    }
    var ct = 0
    var sum = 0
    while (ct < k && (bothLike.isNotEmpty() || (aLikes.isNotEmpty() && bLikes.isNotEmpty()))) {
        val both = if (bothLike.isEmpty()) 1_000_000 else bothLike.peek()
        val separate = if (aLikes.isEmpty() || bLikes.isEmpty()) 1_000_000 else aLikes.peek() + bLikes.peek()
        if (both < separate) {
            sum += both
            bothLike.poll()
        } else {
            sum += separate
            aLikes.poll()
            bLikes.poll()
        }
        ct++
    }
    if (ct == k) {
        print(sum)
    } else {
        print(-1)
    }
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