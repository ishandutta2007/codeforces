fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    repeat(numCases) {
        val (maxVal, mod) = br.readLine().split(' ').map(String::toLong)
        val mvInt = maxVal.toInt()
        val numBits = 32 - Integer.numberOfLeadingZeros(mvInt)
        val dp = LongArray(numBits)
        dp[0] = 1
        for (i in 1 until numBits) {
            val numsToChoose = 1L shl (i - 1)
            dp[i] = dp[i - 1] * (numsToChoose + 1L)
            dp[i] %= mod
        }
        val numsToChoose = maxVal - Integer.highestOneBit(mvInt).toLong() + 1L
//        dp[numBits] = ((numsToChoose + 1L) * dp.last() - 1L) % mod

        sb.append(((numsToChoose + 1L) * dp.last() - 1L + mod) % mod)
        sb.append('\n')
    }
    print(sb)
}