fun main() {
    val br = System.`in`.bufferedReader()
    val (n, x) = br.readLine().split(" ").map { it.toInt() }
    val cts = IntArray(x + 1)
    br.readLine().split(" ").forEach { num ->
        cts[num.toInt()]++
    }
    var good = true
    for (i in 1 until x) {
        cts[i + 1] += cts[i] / (i + 1)
        cts[i] %= (i + 1)
        if (cts[i] != 0) good = false
    }
    if (good) {
        println("YES")
    } else {
        println("NO")
    }
}