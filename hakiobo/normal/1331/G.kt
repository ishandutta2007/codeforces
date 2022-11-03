import kotlin.math.absoluteValue
import kotlin.math.sqrt

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val nums = IntArray(11){
        br.readLine().toInt()
    }.reversed().forEach{
        val num = sqrt(it.absoluteValue.toDouble()) + 5 * it * it * it
        sb.append(String.format("f(%d) = ", it))
        if(num > 400){
            sb.append("MAGNA NIMIS!\n")
        } else {
            sb.append(String.format("%.2f\n", num))
        }
    }
    print(sb)
}