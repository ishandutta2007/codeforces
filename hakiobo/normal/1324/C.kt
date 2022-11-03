
import java.lang.StringBuilder
import java.lang.System.`in`
import kotlin.math.max

fun main() {
    val br = `in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    for(case in 1..numCases){
        val input = br.readLine()
        var curStreak = 0
        var maxStreak = 0
        for(c in input.toCharArray()){
            if(c == 'L'){
                curStreak++
                maxStreak = max(maxStreak, curStreak)
            } else {
                curStreak = 0
            }
        }
        sb.append(maxStreak + 1)
        sb.append('\n')
    }
    print(sb)
}