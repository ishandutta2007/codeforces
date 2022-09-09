import kotlin.math.max

fun main() {
    fun readInt() = readLine()!!.toInt()
    fun readInts() = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
    repeat(readInt()) {
        val n = readInt()
        val s = readLine()!!
        val a = readLine()!!
        var ok = true
        var ans = 0
        var ch = -1
        for (i in 0 until n - 3)
            if (a[i] == '1') {
                if (i + 1 < n - 3 && a[i + 1] == '1') ok = false
                if (i + 3 < n - 3 && a[i + 3] == '1') ok = false
                if (ch == i) {
                    if (s[i + 2] != '(') ans += 1
                    if (s[i + 3] != ')') ans += 1
                    ch = i + 2
                } else if (i + 2 < n - 3 && a[i + 2] == '1') {
                    if (s[i] != '(') ans += 1
                    if (s[i + 1] != ')') ans += 1
                    if (s[i + 2] != '(') ans += 1
                    if (s[i + 3] != ')') ans += 1
                    ch = i + 2
                } else {
                    var l1 = 0
                    var l2 = 0
                    if (s[i] != '(') l1 += 1
                    if (s[i + 1] != ')') l1 += 1
                    if (s[i + 2] != '(') l1 += 1
                    if (s[i + 3] != ')') l1 += 1
                    if (s[i] != '(') l2 += 1
                    if (s[i + 1] != '(') l2 += 1
                    if (s[i + 2] != ')') l2 += 1
                    if (s[i + 3] != ')') l2 += 1
                    ans += minOf(l1, l2)
                }
            }
        println(if (ok) ans else -1)
    }
}