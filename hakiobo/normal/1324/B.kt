
import java.lang.StringBuilder
import java.lang.System.`in`

fun main() {
    val br = `in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    for (case in 1..numCases) {
        val size = br.readLine().toInt()
        val seq = br.readLine().split(' ').map(String::toInt)
        var prev = seq.first()
        val prevNums = HashSet<Int>()
        var good = false
        for (cur in seq.drop(1)) {
            if (cur in prevNums) {
                good = true
            }
            prevNums.add(prev)
            prev = cur
        }
        if (good) {
            sb.append("YES\n")
        } else {
            sb.append("NO\n")
        }
    }
    print(sb)
}