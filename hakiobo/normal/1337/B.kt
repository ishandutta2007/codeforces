fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    repeat(numCases){
        val (x, n, m) = br.readLine().split(' ').map(String::toInt)
        val hpFromM = 10 * m
        var cur = x
        for(cast in 0 until n){
            if(cur <= m * 10){
                break
            }
            cur /= 2
            cur += 10
        }
        if(cur <= m * 10){
            sb.append("YES\n")
        } else{
            sb.append("NO\n")
        }
    }
    print(sb)
}