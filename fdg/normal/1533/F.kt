import java.lang.Integer.max

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

private fun eq(c: Char, v: Int):Int {
    return if ((c - '0').toInt() == v) 1 else 0
}

fun main(args: Array<String>) {
    val s = readLn()
    val n = s.length

    val zero = Array<Int>(n) {0}
    for (i in 1..n)
        zero[i - 1] = eq(s[i - 1], 0) + if (i == 1) 0 else zero[i - 2]
    val one = Array<Int>(n) {0}
    for (i in 1..n)
        one[i - 1] = eq(s[i - 1], 1) + if (i == 1) 0 else one[i - 2]

    println((1..n).map {
        var last = -1
        var cnt = 0

        while (last < n - 1) {
            var l = last + 1
            var r = n
            while (r - l > 1) {
                val mid = (l + r) / 2

                val c0 = zero[mid] - (if (last >= 0) zero[last] else 0)
                val c1 = one[mid] - (if (last >= 0) one[last] else 0)
                if (c0 <= it || c1 <= it) l = mid
                else r = mid
            }
            last = l
            cnt++
        }
        cnt
    }.joinToString(" "))
}