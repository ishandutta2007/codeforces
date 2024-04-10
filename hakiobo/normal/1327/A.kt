import java.lang.StringBuilder
import java.lang.System.`in`

fun main() {
    val br = `in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    repeat(numCases){
        val (n, k) = br.readLine().split(' ').map(String::toLong)
        if(k * k > n || ((k xor n) and 1L) != 0L){
            sb.append("NO\n")
        } else {
            sb.append("YES\n")
        }
    }
    print(sb)
}