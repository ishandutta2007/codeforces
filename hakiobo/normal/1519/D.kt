import kotlin.math.max
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readLine().toInt()
    val a = br.readLine().split(" ").map { it.toLong() }
    val b = br.readLine().split(" ").map { it.toLong() }
    var baseSum = 0L

    for (x in 0 until n) {
        baseSum += a[x] * b[x]
    }
    var best = baseSum
    for (i in 1 until (n - 1)) {
        var cur = baseSum
        for (x in 1..(min(i, n - 1 - i))) {
            cur -= a[i + x] * b[i + x]
            cur -= a[i - x] * b[i - x]
            cur += a[i + x] * b[i - x]
            cur += a[i - x] * b[i + x]
            best = max(best, cur)
        }
    }
    for (i in 1 until n) {
        val j = i - 1
        var cur = baseSum
        cur -= a[j] * b[j]
        cur -= a[i] * b[i]
        cur += a[i] * b[j]
        cur += a[j] * b[i]
        best = max(best, cur)

        for (x in 1..min(j, n - 1 - i)) {
            cur -= a[i + x] * b[i + x]
            cur -= a[j - x] * b[j - x]
            cur += a[i + x] * b[j - x]
            cur += a[j - x] * b[i + x]
            best = max(best, cur)
        }

    }
    print(best)
}