import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    repeat(numCases){
        val n = br.readLine().toInt()
        val nums = br.readLine().split(' ').map(String::toInt)
        var maxDif = 0
        var maxFound = nums.first()
        nums.forEach{num ->
            maxDif = max(maxDif, maxFound - num)
            maxFound = max(num, maxFound)
        }
        sb.append(32 - Integer.numberOfLeadingZeros(maxDif))
        sb.append('\n')
    }
    print(sb)
}