import kotlin.math.max
import kotlin.math.min
import kotlin.system.exitProcess

fun main() {
    val br = System.`in`.bufferedReader()
    val (n, m) = br.readLine().split(' ').map(String::toLong)
    val sizes = br.readLine().split(' ').map(String::toLong)
    val totalPaint = sizes.sum()
    if (totalPaint < n) {
        print(-1)
    } else {
        val sb = StringBuilder()
        var paintLeft = totalPaint
        var flexPaint = totalPaint - m
        var curPos = 1
        sizes.forEachIndexed { id, size ->
            paintLeft -= size
            flexPaint -= size - 1
            if (id + size > n) {
                print(-1)
                exitProcess(0)
            } else {
                sb.append(curPos)
                sb.append(' ')
                curPos += max(1, min(size, n - (curPos + paintLeft) + 1)).toInt()
            }
        }
        print(sb)
    }
}