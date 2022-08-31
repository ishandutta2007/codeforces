import kotlin.system.exitProcess

fun main() {
    val n = readLine()!!.toInt()
    var a = readLine()!!.split(' ').map(String::toInt)
    var ar = Array(n) {i -> Pair(a[i], i)}
    ar.sortWith(compareBy { it.first })
    var ans = mutableListOf<Int>(ar[0].second + 1)
    for (i in 1 until n) {
        if (ar[i].first != ar[i - 1].first) {
            ans.add(ar[i].second + 1)
            if (ans.size == 3) {
                println(ans.joinToString(prefix = "", postfix = "", separator = " "))
                exitProcess(0)
            }
        }
    }
    println("-1 -1 -1")
}