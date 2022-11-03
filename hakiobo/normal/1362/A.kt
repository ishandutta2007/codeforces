import kotlin.math.absoluteValue

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    repeat(numCases) {
        var (a, b) = br.readLine().split(' ').map(String::toLong)
        var dif = 0
        while (a and 1L == 0L) {
            a = a shr 1
            dif++
        }
        while (b and 1L == 0L) {
            b = b shr 1
            dif--
        }
        dif = dif.absoluteValue + 2
        if(a != b){
            sb.append(-1).append('\n')
        } else {
            sb.append(dif / 3).append('\n')
        }
    }
    print(sb)
}