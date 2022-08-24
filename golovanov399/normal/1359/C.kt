import kotlin.math.*

fun solve() {
    val (h, c, t) = readLine()!!.split(' ').map(String::toInt)
    if (t > h) {
        println(1)
        return
    } else if (2 * t <= (h + c)) {
        println(2)
        return
    }
    // h
    // (h + c) / 2
    // (h * (k + 1) + c * k) / (2k + 1)
    // (h * (k + 2) + c * (k + 1)) / (2k + 3)

    // (h * (k + 1) + c * k) / (2k + 1) >= t
    // (h - t)(k + 1) >= (t - c)k
    // (h - t)/(t - c) >= k/(k+1) = 1 - 1/(k+1)
    // 1/(k+1) >= 1 - (h - t)/(t - c)
    // k + 1 <= 1/(1 - (h - t)/(t - c))
    // k + 1 <= (t - c)/(t - c - h + t)
    val k = (t - c)/(t - c - h + t) - 1
    val m = 2L * (2 * k + 1) * (2 * k + 3)
    val diffs = listOf<Long>(
            h * m,
            (h + c) * (m / 2),
            m / (2 * k + 1) * (1L * h * (k + 1) + 1L * c * k),
            m / (2 * k + 3) * (1L * h * (k + 2) + 1L * c * (k + 1))
    ).map {abs(t * m - it)}
    val answers = listOf<Int>(1, 2, 2 * k + 1, 2 * k + 3)
    var res = 0
    for (i in diffs.indices) {
        if (diffs[i] < diffs[res]) {
            res = i
        }
    }
    println(answers[res])

    // h -> h * 2 * (2k + 1) * (2k + 3)
    // (h + c) / 2
    // (h * (k + 1) + c * k) / (2k + 1)
    // (h * (k + 2) + c * (k + 1)) / (2k + 3)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}