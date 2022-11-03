fun main() {
    val br = System.`in`.bufferedReader()
    val t = br.readLine().toInt()
    val res = List(t) {
        val (n, m, k) = br.readLine().split(" ").map { it.toInt() }
        if (k == n * m - 1) "YES" else "NO"
    }
    print(res.joinToString("\n"))
}