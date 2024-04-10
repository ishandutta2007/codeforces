fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    repeat(numCases){
        val (n, k1, k2) = br.readLine().split(' ').map(String::toInt)
        val excursion = br.readLine()
        val s = (k2 - k1).coerceAtMost(k1)
        var m = 0L
        var doS = false
        for(c in excursion){
            doS = if(c == '1'){
                if(doS){
                    m += s
                    false
                } else {
                    m += k1
                    true
                }
            } else {
                false
            }
        }
        sb.append(m).append('\n')
    }
    print(sb)
}