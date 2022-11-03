
import java.lang.StringBuilder
import java.lang.System.`in`

fun main() {
    val br = `in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    for (case in 1..numCases) {
        val size = br.readLine().toInt()
        val nums = br.readLine().split(' ').map(String::toInt)
        var firstOddID = -1
        var secondOddID = -1
        var evenID = -1
        for (id in nums.indices) {
            if (nums[id] and 1 == 0) {
                evenID = id + 1
                break
            } else if (firstOddID == -1) {
                firstOddID = id + 1
            } else {
                secondOddID = id + 1
                break
            }
        }
        when {
            evenID != -1 -> {
                sb.append("1\n")
                sb.append(evenID)
            }
            secondOddID != -1 -> {
                sb.append("2\n")
                sb.append(firstOddID)
                sb.append(' ')
                sb.append(secondOddID)
            }
            else -> {
                sb.append(-1)
            }
        }
        sb.append('\n')
    }
    print(sb)
}