/**
 * Created by ezhang on 5/28/19.
 */

import java.util.LinkedList;

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun solve(pre: Array<Int>, sz: Array<Int>): Boolean {
    var s = 0
//    println(pre.contentToString())
//    println(sz.contentToString())
    for (blank in sz) {
        var lo = s
        var hi = pre.size - 1
        while (lo != hi) {
            var mid = (lo + hi + 1) / 2
            if (pre[mid] - pre[s] <= blank)
                lo = mid
            else
                hi = mid - 1
        }
        s = lo
//        println(s)
    }
    return s == pre.size - 1
}

fun main(args : Array<String>) {
    val (n, m) = readInts()
    val ar = readInts()
    var pre = Array<Int>(n + 1){0}
    for (i in 1..n)
        pre[i] = pre[i - 1] + ar[i - 1]
    val q = readInt()
    for (tc in 1..q) {
        val w = readInts()
        var ar = Array<Int>(w.size){0}
        var pr = 0
        for (i in 1..w[0]) {
            ar[i - 1] = w[i] - pr - 1;
            pr = w[i];
        }
        ar[w.size - 1] = m - pr
        println(if (solve(pre, ar)) "YES" else "NO")
    }
}