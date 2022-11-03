
import java.lang.StringBuilder
import java.lang.System.`in`
import kotlin.math.max

fun main() {
    val br = `in`.bufferedReader()
    val sb = StringBuilder()
    val numElements = br.readLine().toInt()
    val b = br.readLine().split(' ').map(String::toInt)
    var curMax = 0
    for(index in b.indices){
        val newA = b[index] + curMax
        curMax = max(curMax, newA)
        sb.append(newA)
        sb.append(' ')
    }
    print(sb)
}