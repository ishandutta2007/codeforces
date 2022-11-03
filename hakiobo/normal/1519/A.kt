import kotlin.math.max
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val t = br.readLine().toInt()
    val res = List(t) {
        val (r, b, d) = br.readLine().split(" ").map { it.toLong() }
        val maxBags = min(r, b)
        if(maxBags * (d + 1) < max(r, b)){
            "NO"
        } else {
            "YES"
        }
    }
    print(res.joinToString("\n"))
}