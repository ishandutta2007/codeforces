fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    repeat(numCases){
        val n = br.readLine().toLong()
        var sum = 0L
        var thing = 0
        while(1L shl thing <= n){
            sum += n shr thing
            thing++
        }
        sb.append(sum).append('\n')
    }
    print(sb)
}