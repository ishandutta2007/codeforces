fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    repeat(numCases) {
        val n = br.readLine().toInt()
        val nums = br.readLine().split(' ').map(String::toInt)
        val isIn = BooleanArray(1024)
        for (num in nums) {
            isIn[num] = true
        }
        var good = false
        for (s in 1 until 1024) {
            good = true
            for (num in nums) {
                if (!isIn[num xor s]) {
                    good = false
                    break
                }
            }
            if (good == true) {
                sb.append(s).append('\n')
                break
            }
        }
        if (!good) {
            sb.append(-1).append('\n')
        }
    }
    print(sb)
}