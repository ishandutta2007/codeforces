
import java.lang.StringBuilder
import java.lang.System.`in`

fun main() {
    val br = `in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    for(case in 1..numCases){
        val len = br.readLine().toInt()
        val nums = br.readLine().split(' ').map(String::toInt).sorted().reversed()
        for(num in nums){
            sb.append(num)
            sb.append(' ')
        }
        sb.append('\n')
    }
    print(sb)
}