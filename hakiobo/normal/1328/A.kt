fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    repeat(numCases){
        val (a, b) = br.readLine().split(' ').map(String::toInt)
        sb.append((b - a%b)%b)
        sb.append('\n')
    }

    print(sb)
}