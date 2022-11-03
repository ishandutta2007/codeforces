fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    repeat(numCases) {
        val n = br.readLine().toInt()
        var q = 3
        while (q <= n) {
            if (n % q == 0) {
                sb.append(n / q).append('\n')
                break
            } else {
                q = 1 + (q shl 1)
            }
        }
    }
    print(sb)
}