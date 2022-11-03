import java.lang.StringBuilder
import java.lang.System.`in`

fun main() {
    val br = `in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    repeat(numCases){
        val num = br.readLine().toInt()
        if(num == 1){
            sb.append(-1)
        } else {
            repeat(num - 1){
                sb.append(3)
            }
            sb.append(4)
        }
        sb.append('\n')
    }
    print(sb)
}