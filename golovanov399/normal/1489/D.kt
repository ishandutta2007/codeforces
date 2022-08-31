import java.util.*
import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    val ans = List<String>(n) { readLine()!! }.sortedWith(compareBy { x -> x.length })
    for (i in 1 until n) {
        if (!ans[i].contains(ans[i - 1])) {
            println("NO")
            return
        }
    }
    println("YES")
    println(ans.joinToString("\n"))
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}