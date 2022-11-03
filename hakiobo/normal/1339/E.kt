fun main() {
    val br = System.`in`.bufferedReader()
    val numCases = br.readLine().toInt()
    val sb = StringBuilder()
    repeat(numCases) {
        val num = br.readLine().toLong()

        var fourPow = 0
        var e = num / 4
        while (e != 0L) {
            fourPow++
            e /= 4
        }
        val base = 1L shl ((fourPow shl 1))
        val n = num - base
        val nMod3 = n % 3
        val n2 = n / 3
        val top = (nMod3 + 1) shl ((fourPow shl 1))
        var ans = 0L
        if (base == 0L) {
            sb.append(ans)
        } else {
            for(shift in 0..fourPow){
                val check = (n2 shr (shift shl 1)) and 3
                ans = ans or ((if(check == 0L) 0L else (1 + (nMod3 + check - 1)%3)) shl (shift shl 1))
            }
            ans = ans or top
            sb.append(ans)
        }
        sb.append('\n')
    }
    print(sb)
}