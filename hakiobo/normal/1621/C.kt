import kotlin.system.exitProcess

fun main() {
    val t = readLine()!!.toInt()
    fun query(x: Int): Int {
        println("? ${x + 1}")
        val ret = readLine()!!.toInt()
        if (ret == -1) exitProcess(0)
        return ret - 1
    }
    repeat(t) {
        val n = readLine()!!.toInt()
        val ans = IntArray(n) { -1 }
        for (x in 0 until n) {
            if (ans[x] == -1) {
                val start = query(x)
                var p = start
                var q = query(x)
                while (q != start) {
                    ans[p] = q
                    p = q
                    q = query(x)
                }
                ans[p] = q
            }
        }
        println("! ${ans.joinToString(" ") { (it + 1).toString() }}")
    }
}