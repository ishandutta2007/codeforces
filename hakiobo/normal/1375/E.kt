import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val n = br.readInt()
    val nums = IntArray(n) { br.readInt() }
    val inversions = Array(n) { mutableListOf<Int>() }
    for (x in 0 until n) {
        for (y in (x + 1) until n) {
            if (nums[x] > nums[y]) {
                inversions[x].add(y)
            }
        }
    }
    val moves = mutableListOf<Pair<Int, Int>>()
    fun doMove(x: Int, y: Int) {
        val tmp = nums[x]
        nums[x] = nums[y]
        nums[y] = tmp
        moves.add(Pair(x + 1, y + 1))
    }

    fun comp(a: Int, b: Int): Int {
        return if (nums[b].compareTo(nums[a]) == 0) {
            b.compareTo(a)
        } else {
            nums[b].compareTo(nums[a])
        }
    }

    val comparator = Comparator(::comp)

    for (x in 0 until n) {
        inversions[x].sortWith(comparator)
    }

    for (x in 0 until n) {
        for (y in inversions[x]) {
            doMove(x, y)
        }
    }
//    if (nums.contentEquals(nums.sorted().toIntArray())) {
        sb.append(moves.size).append('\n')
        for (move in moves) {
            sb.append(move.first).append(' ').append(move.second).append('\n')
        }
//    } else {
//        sb.append(-1)
//    }

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