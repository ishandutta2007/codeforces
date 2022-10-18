import java.lang.Integer.max

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
    val n = readInt()
    val a = readInts().sorted()
    val b = readInts().sorted()

    val pref = Array<Int>(n) {0}
    for (i in 1..n)
        pref[i - 1] = if (i == 1) b[i - 1] - a[i - 1] else Integer.max(b[i - 1] - a[i - 1], pref[i - 2])

    val suf = Array<Int>(n) {0}
    for (i in n downTo 1)
        suf[i - 1] = if (i == n) b[i] - a[i - 1] else Integer.max(b[i] - a[i - 1], suf[i])

    val m = readInt()
    val arr = readInts()
    println((1..m).map {
        var pos = a.binarySearch(arr[it - 1])
        if (pos < 0) pos = -pos - 1

        var ret = b[pos] - arr[it - 1]
        if (pos > 0) ret = Integer.max(ret, pref[pos - 1])
        if (pos < n) ret = Integer.max(ret, suf[pos])
        ret
    }.joinToString(" "))
}