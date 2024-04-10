fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readLine().toInt()
    repeat(t) {
        val (n, m) = br.readLine().split(" ").map { it.toInt() }
        val a = br.readLine().split(" ").map { it.toInt() }
        val b = br.readLine().split(" ").map { it.toInt() }
        var ans = -1
        for (x in 0 until n) {
            if (ans >= 0) continue
            for (y in 0 until m) {
                if (ans >= 0) continue
                if (a[x] == b[y]) {
                    ans = a[x]
                }
            }
        }
        if (ans == -1) {
            sb.appendLine("NO")
        } else {
            sb.appendLine("YES").appendLine("1 $ans")
        }
    }
    println(sb)
}