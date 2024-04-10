/**
 * Created by ezhang on 5/28/19.
 */

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

var fen = Array<Int>(200013){0}

fun query(x: Int): Int {
    var i = x + 1
    var ans = 0
    while (i > 0) {
        ans += fen[i]
        i -= i and -i;
    }
    return ans
}

fun update(x: Int) {
    var i = x + 1
    while (i < 200013) {
        fen[i] += 1
        i += i and -i
    }
}

fun main(args : Array<String>) {
    val n = readInt()
    var ar = readInts()
    var idx = Array<Int>(n){0}
    for (i in 0..n-1)
        idx[i] = n - 1 - i
    var ii = idx.sortedBy { -ar[it] }
    var ans = 0
    for (i in ii) {
        if (query(i) >= 2)
            ans += 1
        update(i)
    }
    println(ans)
}