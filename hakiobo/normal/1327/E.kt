import java.lang.StringBuilder
import java.lang.System.`in`

const val MOD = 998244353L

fun main() {
    val n = `in`.bufferedReader().readLine().toInt()
    val sb = StringBuilder()
    var activeBlocks = 10L
    var active1Blocks = 10L
    val nums = LongArray(n)
    nums[0] = 10L
    repeat(n - 1) {

        nums[it + 1] = (9L * activeBlocks + 10L * nums[it] - active1Blocks + MOD) % MOD


        active1Blocks = 9L * activeBlocks
        activeBlocks += 9L * activeBlocks
        activeBlocks %= MOD
        active1Blocks %= MOD
    }
    for (x in n - 1 downTo 0) {
        sb.append(nums[x])
        sb.append(' ')
    }
    print(sb)
}