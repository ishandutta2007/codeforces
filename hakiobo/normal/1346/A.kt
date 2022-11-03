fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    repeat(numCases) {
        val (n, k) = br.readLine().split(' ').map(String::toInt)
        val thing = 1 + k + k * k + k * k * k
        val a = n / thing
        sb.append(a).append(' ').append(k * a).append(' ').append(k * k * a).append(' ').append(k * k * k * a).append('\n')
    }
    print(sb)
}