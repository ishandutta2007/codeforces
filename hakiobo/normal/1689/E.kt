import java.io.BufferedReader
import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    val baseGrid = Array(30) { IntArray(30) }
    val connected = Array(30) { i -> BooleanArray(30) { j -> baseGrid[i][j] != 0 } }
    repeat(t) {
        for (i in 0 until 30) {
            baseGrid[i].fill(0)
        }
        var numMoves = 0
        val n = br.readInt()
        val nums = IntArray(n) { br.readInt() }

        fun adjust(num: Int, delta: Int) {
            var temp = num
            while (temp != 0) {
                val bit = temp.countTrailingZeroBits()
                baseGrid[bit][bit] += delta
                temp = temp xor (1 shl bit)
                var temp2 = temp
                while (temp2 != 0) {
                    val bit2 = temp2.countTrailingZeroBits()
                    baseGrid[bit][bit2] += delta
                    baseGrid[bit2][bit] += delta
                    temp2 = temp2 xor (1 shl bit2)
                }
            }
        }
        for (i in 0 until n) {
            if (nums[i] == 0) {
                nums[i]++
                numMoves++
            }
            adjust(nums[i], 1)
        }
        fun isConnected(): Boolean {
            val seen = BooleanArray(30)
            val order = IntArray(30)
            var inIdx = 0
            var outIdx = 0
            var bad = false
            for(i in 0 until 30) {
                if(!seen[i] && baseGrid[i][i] != 0) {
                    if(bad) return false
                    bad = true
                    order[inIdx++] = i
                    seen[i] = true
                    while (outIdx < inIdx) {
                        val node = order[outIdx++]
                        for(adj in 0 until 30) {
                            if(!seen[adj] && baseGrid[node][adj] != 0) {
                                seen[adj] = true
                                order[inIdx++] = adj
                            }
                        }
                    }
                }
            }
            return true
        }

        var most = 0
        if (!isConnected()) {
            numMoves++
            for (i in 0 until n) {
                if (nums[i] and 1 == 0 && nums[i] != 1) {
                    most = max(most, nums[i].countTrailingZeroBits())
                    adjust(nums[i]--, -1)
                    adjust(nums[i], 1)
                    if (isConnected()) break
                    adjust(nums[i]++, -1)
                    adjust(++nums[i], 1)
                    if (isConnected()) break
                    adjust(nums[i]--, -1)
                    adjust(nums[i], 1)
                }
            }
            if (!isConnected()) {
                numMoves++
                for (i in 0 until n) {
                    if (nums[i].countTrailingZeroBits() == most) {
                        nums[i]--
                        for (j in i + 1 until n) {
                            if (nums[j].countTrailingZeroBits() == most) {
                                nums[j]++
                                break
                            }
                        }
                        break
                    }
                }
            }
        }
        
        bw.appendLine(numMoves.toString())
        bw.appendLine(nums.joinToString(" "))
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