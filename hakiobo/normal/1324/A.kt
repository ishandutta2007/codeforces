
import java.lang.StringBuilder
import java.lang.System.`in`

fun main() {
    val br = `in`.bufferedReader()
    val numCases = br.readLine().toInt()
    val sb = StringBuilder()
    for(case in 1..numCases){
        val numCols = br.readLine().toInt()
        val nums = br.readLine().split(' ').map(String::toInt)
        val parity = nums.first() and 1
        var good = true
        for(x in 1 until numCols){
            if(nums[x] and 1 != parity){
                good = false
            }
        }
        if(good){
            sb.append("YES\n")
        } else {
            sb.append("NO\n")
        }
    }
    print(sb)
}