import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    repeat(numCases) {
        val numNums = br.readLine().toInt()
        val nums = br.readLine().split(' ').map(String::toInt)
        val colorsUsed = TreeMap<Int, Int>()
        val colors = IntArray(numNums) { id ->
            val num = nums[id]
            val gcd = when {
                num % 2 == 0 -> 2
                num % 3 == 0 -> 3
                num % 5 == 0 -> 5
                num % 7 == 0 -> 7
                num % 11 == 0 -> 11
                num % 13 == 0 -> 13
                num % 17 == 0 -> 17
                num % 19 == 0 -> 19
                num % 23 == 0 -> 23
                num % 29 == 0 -> 29
                else -> 31
            }
            if (gcd !in colorsUsed) {
                colorsUsed[gcd] = 2
            }
            gcd
        }
        var id = 1
        for (color in colorsUsed) {
            colorsUsed[color.key] = id++
        }
        sb.append(colorsUsed.size)
        sb.append('\n')
        colors.forEach { color ->
            sb.append(colorsUsed[color]!!)
            sb.append(' ')
        }
        sb.append('\n')
    }
    print(sb)
}