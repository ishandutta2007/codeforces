fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readLine().toInt()
    repeat(t) {
        val (n, k) = br.readLine().split(" ").map { it.toInt() }
        val s = br.readLine()
        var count = 0
        var extra = 0
        var cur = 0
        for(c in s){
            if(c == '('){
                cur++
            } else {
                cur--
                if(cur == 0){
                    count++
                } else if(extra < k){
                    extra++
                    count++
                }
            }
        }
        sb.append(count).append("\n")
    }
    print(sb)
}