
import java.lang.System.`in`

fun main() {
    val br = `in`.bufferedReader()
    val sb = StringBuilder(0)
    val numCases = br.readLine().toInt()
    for (case in 1..numCases){
        val (n, m) = br.readLine().split(' ').map(String::toInt)
        if(n % m == 0){
            sb.append("YES\n")
        } else {
            sb.append("NO\n")
        }
    }
    print(sb)
}