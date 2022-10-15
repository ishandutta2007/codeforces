/**
 * Created by ezhang on 5/28/19.
 */

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun test(a: Array<Int>, b: Array<Int>, x: Int, y: Int): Boolean {
    for (i in (0..a.size - 1)) {
        if (a[i] != x && b[i] != x && a[i] != y && b[i] != y) {
            return false;
        }
    }
    return true;
}

fun test(a: Array<Int>, b: Array<Int>, x: Int): Boolean {
    for (i in (0..a.size - 1)) {
        if (a[i] != x && b[i] != x) {
            return test(a, b, x, a[i]) || test(a, b, x, b[i]);
        }
    }
    return true;
}

fun main(args : Array<String>) {
    val (n, m) = readInts()
    var a = Array<Int>(m){0};
    var b = Array<Int>(m){0};
    for (i in (0..m-1)) {
        var (k, l) = readInts()
        a[i] = k; b[i] = l;
    }

    val ans = test(a, b, a[0]) || test(a, b, b[0]);
    println(if (ans) "YES" else "NO");
}