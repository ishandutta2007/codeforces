
import java.lang.StringBuilder
import java.lang.System.`in`

fun main() {
    val br = `in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    for(case in 1..numCases){
        val ignore = br.readLine().toInt()
        val nums = br.readLine().split(' ').map(String::toInt)
        val set = HashSet<Int>()
        for(num in nums){
            set.add(num)
        }
        sb.append(set.size)
        sb.append('\n')
    }
    print(sb)
}