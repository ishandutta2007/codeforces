import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val h = br.readInt()
        val g = br.readInt()
        val nums = IntArray(1 shl h)


        var sum = 0L
        for (i in 1 until nums.size) {
            nums[i] = br.readInt()
            sum += nums[i]
        }
        val sectionToRemoveFrom = IntArray(1 shl h)
        val topBit = 1 shl (g - 1)
        for (i in (1 shl (g - 1)) until (1 shl g)) {
            sectionToRemoveFrom[i] = i xor topBit
        }
        for (i in (1 shl g) until (1 shl h)) {
            sectionToRemoveFrom[i] = sectionToRemoveFrom[i shr 1]
        }
        for (i in (1 shl (g - 1)) - 1 downTo 1) {
            val left = i shl 1
            val right = left + 1
            sectionToRemoveFrom[i] = if (nums[left] > nums[right]) {
                sectionToRemoveFrom[left]
            } else {
                sectionToRemoveFrom[right]
            }
        }
        val numsLeft = IntArray(1 shl (g - 1)) { (1 shl (h - g + 1)) - 2 }

        val moves = IntArray((1 shl h) - (1 shl g))
        var movesMade = 0
        fun f(node: Int) {
            val left = node * 2
            val right = left + 1
            if (left >= nums.size || nums[left] == nums[right]) {
                nums[node] = 0
                return
            }
            if (nums[left] > nums[right]) {
                nums[node] = nums[left]
                f(left)
            } else {
                nums[node] = nums[right]
                f(right)
            }
            if (nums[left] == nums[right]) return
            sectionToRemoveFrom[node] = if (nums[left] > nums[right]) {
                sectionToRemoveFrom[left]
            } else {
                sectionToRemoveFrom[right]
            }
        }

        fun findMove(node: Int) {
            if (node >= nums.size) return
            while (numsLeft[sectionToRemoveFrom[node]] != 0) {
                numsLeft[sectionToRemoveFrom[node]]--
                moves[movesMade++] = node
                sum -= nums[node]
                f(node)
            }
            val left = node shl 1
            val right = left + 1
            findMove(left)
            findMove(right)
        }
        findMove(1)
        bw.appendLine(sum.toString())
        bw.appendLine(moves.joinToString(" "))
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