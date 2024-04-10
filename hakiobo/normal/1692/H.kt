import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val nums = IntArray(n) { br.readInt() }
        val curNums = mutableListOf<Int>()
        val curCts = mutableListOf<Int>()
        val curLefts = mutableListOf<Int>()
        var bestCt = 1
        var bestL = 1
        var bestR = 1
        for (i in 0 until n) {
            val num = nums[i]
            var found = false
            var j = 0
            while (j < curNums.size) {
                if (num == curNums[j]) {
                    found = true
                    if (++curCts[j] > bestCt) {
                        bestCt = curCts[j]
                        bestL = curLefts[j] + 1
                        bestR = i + 1
                    }
                    j++
                } else if (--curCts[j] == 0) {
                    curNums.removeAt(j)
                    curCts.removeAt(j)
                    curLefts.removeAt(j)
                } else {
                    j++
                }
            }
            if (!found) {
                curCts += 1
                curLefts += i
                curNums += num
            }
        }
        bw.appendLine("${nums[bestL - 1]} $bestL $bestR")
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