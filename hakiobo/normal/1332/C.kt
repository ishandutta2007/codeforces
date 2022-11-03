import kotlin.math.max


fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    repeat(numCases) {
        val (n, k) = br.readLine().split(' ').map(String::toInt)
        val s = br.readLine()
        val occurences = Array((k + 1) / 2) { IntArray(26) }
        for (block in 0 until n / k) {
            for (x in 0..(k - 1) / 2) {
                val i2 = k - x - 1
                occurences[x][s[block * k + x] - 'a']++
                if (i2 != x) {
                    occurences[x][s[block * k + i2] - 'a']++
                }
            }
        }
        var cost = 0
        occurences.forEach { letterCounts ->
            var maxCnt = 0
            var tot = 0
            letterCounts.forEach { cnt ->
                maxCnt = max(maxCnt, cnt)
                tot += cnt
            }
            cost += tot - maxCnt
        }
        sb.append(cost)
        sb.append('\n')
    }
    print(sb)
}