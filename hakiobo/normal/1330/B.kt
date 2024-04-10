import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val numCases = br.readLine().toInt()
    val sb = StringBuilder()
    repeat(numCases) {
        val numNums = br.readLine().toInt()
        val nums = br.readLine().split(' ').map(String::toInt)
        val max = nums.max()!!
        val possible = HashSet<Int>()
        possible.add(max)
        possible.add(numNums - max)
        val sb2 = StringBuilder()
        var numSols = 0

        
        possible.forEach {
            var maxSeenStart = 0
            var maxSeenEnd = 0
            val numSetStart = HashSet<Int>()
            val numSetEnd = HashSet<Int>()
            for (x in 0 until it) {
                val num = nums[x]
                maxSeenStart = max(maxSeenStart, num)
                numSetStart += num
            }
            for (x in it until numNums) {
                val num = nums[x]
                maxSeenEnd = max(maxSeenEnd, num)
                numSetEnd += num
            }
            if (it == maxSeenStart && maxSeenStart == numSetStart.size && numNums - it == maxSeenEnd && maxSeenEnd == numSetEnd.size) {
                numSols++
                sb2.append(it)
                sb2.append(' ')
                sb2.append(numNums - it)
                sb2.append('\n')
            }
        }
        sb.append(numSols)
        sb.append('\n')
        sb.append(sb2)
    }
    print(sb)
}