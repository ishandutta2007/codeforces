import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val m = br.readInt()
    val grid = Array(n) { IntArray(m) { br.readInt() } }
    val nums = mutableListOf<Pair<Int, Int>>()
//    val cols = mutableListOf<Pair<Int,Int>>()
//    val cols = TreeMap<Int, MutableList<Int>>()
    for (row in 0 until n) {
        for (col in 0 until m) {
            val c = grid[row][col]
            nums += c to row
            nums += c + 100_000 to col
        }
    }
    nums.sortWith { a, b ->
        if (a.first == b.first) {
            a.second.compareTo(b.second)
        } else {
            a.first.compareTo(b.first)
        }
    }

    var ans = 0L
    var prevColor = 0
    var dist = 0L
    var prev = 0
    var ct = 0L

    for ((color, cur) in nums) {
        if (prevColor == color) {
            dist += ct * (cur - prev)
            ans += dist
            prev = cur
            ct++
        } else {
            dist = 0L
            prev = cur
            ct = 1
            prevColor = color
        }
    }

    println(ans)
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