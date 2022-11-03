
import java.lang.StringBuilder
import java.lang.System.`in`

fun main() {
    val br = `in`.bufferedReader()
    val numCases = br.readLine().toInt()
    val sb = StringBuilder()
    for (case in 1..numCases) {
        val sum = br.readLine().toInt()

        sb.append(1)
        sb.append(' ')
        sb.append(sum - 1)
        sb.append('\n')
    }
    print(sb)
}