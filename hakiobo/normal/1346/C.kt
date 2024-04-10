fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    repeat(numCases){
        val (n, k, x, y) = br.readLine().split(' ').map(String::toLong)
        val nums = br.readLine().split(' ').map(String::toLong).sorted()
        var tot = nums.sum()
        var seconds = 0L
        var early = Long.MAX_VALUE
        val target = n * k
        for(i in nums.lastIndex downTo 0){
            if(early == Long.MAX_VALUE && tot <= target){
                early = seconds + y
            }
            val num = nums[i]
            if(num > k){
                tot -= num
                seconds += x
            } else {
                break
            }
        }
        sb.append(seconds.coerceAtMost(early)).append('\n')
    }
    print(sb)
}