import java.io.BufferedReader

fun main() {
    val (n, k) = readLine()!!.split(" ").map { it.toInt() }
    val nums = IntArray(n)
    val baseOr = IntArray(3) { idx ->
        println("or ${1 + idx} ${1 + (1 + idx) % 3}")
        readLine()!!.toInt()
    }
    val baseAnd = IntArray(3) { idx ->
        println("and ${1 + idx} ${1 + (1 + idx) % 3}")
        readLine()!!.toInt()
    }
    for (x in 0 until 3) {
        val orPart = (baseOr[x] or baseOr[(2 + x) % 3]) xor baseOr[(x + 1) % 3]
        val andPart = baseAnd[x] or baseAnd[(2 + x) % 3]

        nums[x] = orPart or andPart
    }
    for (x in 3 until n) {
        println("or 1 ${x + 1}")
        val orPart = readLine()!!.toInt()
        println("and 1 ${x + 1}")
        val andPart = readLine()!!.toInt()
        nums[x] = (nums[0] xor orPart) or andPart
    }
    val sorted = nums.sortedArray()
    println("finish ${sorted[k - 1]}")

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