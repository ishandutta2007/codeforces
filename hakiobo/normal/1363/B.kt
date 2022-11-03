fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    repeat(numCases){
        val s = br.readLine()
        val l = s.length
        var numFlips = 0
        for(c in s){
            if(c == '0'){
                numFlips++
            }
        }
        var best = numFlips.coerceAtMost(l - numFlips)
        for(c in s){
            if(c == '1'){
                numFlips++
            } else {
                numFlips--
            }
            best = best.coerceAtMost(numFlips)
            best = best.coerceAtMost(l - numFlips)
        }
        sb.append(best).append('\n')
    }
    print(sb)
}