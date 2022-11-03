import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    fun query(nums: List<Int>): Long {
        return if (nums.isNotEmpty()) {
            println("? %d %s".format(nums.size, nums.joinToString(" ")))
            br.readLong()
        } else {
            0L
        }
    }
    val n = br.readInt()
    val q = mutableListOf<Int>()
    val qResults = mutableListOf<Long>()
    val password = LongArray(n)
    for (x in 0 until 13) {
        val mask = 1 shl x
        var numSingles = 0
        for (num in 1..n) {
            while (Integer.bitCount(num + numSingles) != 6) {
                numSingles++
            }
            if ((num + numSingles) and mask != 0) {
                q += num
            }
        }
        qResults += query(q)
        q.clear()

        numSingles = 0
        for (num in 1..n) {
            while (Integer.bitCount(num + numSingles) != 6) {
                numSingles++
            }
            if (mask and (num + numSingles) == 0) {
                password[num - 1] = password[num - 1] or qResults.last()
            }
        }
    }
    println("! %s".format(password.joinToString(" ")))
}


private const val SPACE_INT = ' '.toInt()
private const val ZERO_INT = '0'.toInt()
private const val CR_INT = '\r'.toInt()

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
    if (read == CR_INT) {
        read()
    }
    return if (neg) -ret else ret
}

@Suppress("DuplicatedCode")
private fun BufferedReader.readLong(): Long {
    var ret = read().toLong()
    while (ret <= SPACE_INT) {
        ret = read().toLong()
    }
    val neg = ret == '-'.toLong()
    if (neg) {
        ret = read().toLong()
    }
    ret -= ZERO_INT
    var read = read()
    while (read >= ZERO_INT) {
        ret *= 10
        ret += read - ZERO_INT
        read = read()
    }
    if (read == CR_INT) {
        read()
    }
    return if (neg) -ret else ret
}