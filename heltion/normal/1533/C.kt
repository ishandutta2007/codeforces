import java.util.*

fun f(n : Int, k : Int, cur : Int) : List<Int>{
    if (n == 1) return listOf(0)
    val nxt = (cur + k - 1) % (n - 1)
    val res = f(n - 1, k, nxt).map{if (it >= cur) it + 1 else it}.toList()
    return listOf(cur) + res
}
fun main() {
    fun readInt() = readLine()!!.toInt()
    fun readInts() = readLine()!!.split(' ').map { it.toInt() }
    repeat (readInt()) {
        val (n, k) = readInts()
        val s = readLine()!!
        val p = f(n, k, 0)
        var rm = s.count{
            it == '1'
        }
        //println(p)
        var res = 0
        for (i in p) if (rm > 0) {
            res += 1
            if (s[i] == '1') rm -= 1
        }
        println(res)
    }
}