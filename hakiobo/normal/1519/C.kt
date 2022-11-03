fun main() {
    val br = System.`in`.bufferedReader()
    val t = br.readLine().toInt()
    val res = List(t) {
        val n = br.readLine().toInt()
        val skillsByUni = List(n) { mutableListOf<Int>() }
        val unis = br.readLine().split(" ").map { it.toInt() - 1 }
        val skills = br.readLine().split(" ").map { it.toInt() }
        for (student in 0 until n) {
            skillsByUni[unis[student]] += skills[student]
        }
        val res = LongArray(n)
        for (uni in 0 until n) {
            skillsByUni[uni].sortDescending()
            var tmp = 0L
            val size = skillsByUni[uni].size
            val prefixSum = LongArray(size) {
                tmp += skillsByUni[uni][it]
                tmp
            }
            for (teamSize in 1..size) {
                res[teamSize - 1] += prefixSum[size - 1 - size % teamSize]
            }
        }
        res
    }
    print(res.joinToString("\n") { it.joinToString(" ") })
}