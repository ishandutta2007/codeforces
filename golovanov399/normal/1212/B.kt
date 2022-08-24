fun inc(M: MutableMap<String, Int>, s: String) {
    M.set(s, (M[s]?:0) + 1)
}

fun main() {
    val n = readLine()!!.toInt()
    val s = readLine()!!
    var cnt = mutableMapOf<String, Int>();
    for (i in 0 until n - 1) {
        inc(cnt, s.substring(i..i+1))
    }
    var max_cnt = 0
    var ans: String = ""
    for ((k, v) in cnt) {
        if (max_cnt < v) {
            max_cnt = v
            ans = k
        }
    }

    println(ans)
}