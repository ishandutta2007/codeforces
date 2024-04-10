fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readLine().toInt()
    println("? 1")
    val answer = StringBuilder("!\n")
    val response = br.readLine().split(" ").map { it.toInt() }
    var oddCount = 0
    var evenCount = 0
    for (x in 1 until n) {
        if (response[x] and 1 == 0) {
            evenCount++
        } else {
            oddCount++
        }
    }
    val addNow = evenCount < oddCount
    val queryParity = if (evenCount < oddCount) 0 else 1
    val toQuery = mutableListOf<Int>()
    for (x in 1 until n) {
        if (response[x] and 1 == queryParity) {
            toQuery += x
        }
        if (response[x] == 1 && addNow) {
            answer.appendLine("1 ${x + 1}")
        }
    }
    for (query in toQuery) {
        println("? ${query + 1}")
        val qResp = br.readLine().split(" ").map { it.toInt() }
        for (x in 0 until n) {
            if (qResp[x] == 1) {
                answer.appendLine("${query + 1} ${x + 1}")
            }
        }
    }
    print(answer)
}