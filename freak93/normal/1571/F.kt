import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    val (n, m) = readInts()

    val competitions = (1..n).map { idx -> readInts() }


    val answer = IntArray(n) { -1 }

    var begin = 0
    for ((index, value) in competitions.withIndex()) {
        val (k, t) = value
        if (t == 1) {
            answer[index] = begin
            begin += k
        }
    }

    var from = Array<Int?>(m + 1) { null }
    from[0] = -1

    val left = m - begin
    val limit = (left + 1) / 2
    var sum = 0
    for ((index, value) in competitions.withIndex()) {
        val (k, t) = value
        if (t == 1) continue

        for (i in min(sum, limit - k) downTo 0) {
            if (from[i] != null && from[i + k] == null) {
                from[i + k] = index
            }
        }

        sum += k
    }

    var found = false
    for (i in 0..(limit + 1)) {
        if (from[i] == null) continue
        if (i > (left + 1) / 2 || sum - i > left / 2) continue 

        found = true
        var aux = begin
        var now = i
        while (now > 0) {
            val idx = from[now]!!
            answer[idx] = aux
            aux += 2 * competitions[idx][0]
            now -= competitions[idx][0]
        }
        break
    }

    if (!found) {
        println(-1)
        return
    }

    begin += 1
    for ((index, value) in competitions.withIndex()) {
        val (k, t) = value
        if (t == 1 || answer[index] >= 0) continue 

        answer[index] = begin
        begin += 2 * k
    }

    println(answer.map { it + 1}.joinToString(" "))
}