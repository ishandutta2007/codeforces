fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    repeat(numCases){
        val (n, x) = br.readLine().split(' ').map(String::toInt)
        val nums = br.readLine().split(' ').map(String::toInt).sorted()
        var contestsLeft = x
        var curID = 0
        var curNum = 1
        while (true){
            while (curID < n && nums[curID] < curNum) curID++
            if(curID == n || nums[curID] != curNum){
                if(contestsLeft == 0){
                    sb.append(curNum - 1)
                    sb.append('\n')
                    break
                }
                contestsLeft--
            }
            curNum++
        }
    }
    print(sb)
}