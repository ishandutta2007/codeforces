fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    repeat(numCases){
        val numSections = br.readLine().toLong()
        sb.append(numSections)
        sb.append('\n')
    }
    print(sb)
}