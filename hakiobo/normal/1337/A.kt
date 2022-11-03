fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    repeat(numCases) {
        val (a, b, c, d) = br.readLine().split(' ').map(String::toInt)
        sb.append(a)
        sb.append(' ')
        sb.append(c)
        sb.append(' ')
        sb.append(c)
        sb.append('\n')
    }
    print(sb)
}