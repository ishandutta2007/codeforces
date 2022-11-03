fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    repeat(numCases) {
        val (n, a, b, c, d) = br.readLine().split(' ').map(String::toInt)
        sb.append(if((c-d).coerceAtLeast(n*(a-b)) <= (c+d).coerceAtMost(n*(a+b))) "Yes\n" else "No\n")
    }
    print(sb)
}