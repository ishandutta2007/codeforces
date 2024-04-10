fun main() {
    val n = readLine()!!.toInt()
    val s = readLine()!!
    var cnt = Array(26) {0}
    for (c in s) {
        cnt[c.hashCode() - 'a'.hashCode()] += 1
    }
    println(if (cnt.max()!! >= 2 || n == 1) "Yes" else "No")
}