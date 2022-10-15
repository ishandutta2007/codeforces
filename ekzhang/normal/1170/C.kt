/**
 * Created by ezhang on 5/28/19.
 */

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun solve(s: String, t: String): Boolean {
    // s -> t
    var idx = 0
    for (i in 0..t.length-1) {
        if (t[i] == '-') {
            if (idx >= s.length || s[idx] == '+')
                return false;
            idx += 1
        }
        else {
            if ((idx < s.length && s[idx] == '+'))
                idx += 1
            else if (idx + 1 < s.length && s[idx] == '-' && s[idx + 1] == '-')
                idx += 2
            else
                return false
        }
    }
    return idx == s.length;
}

fun main(args : Array<String>) {
    val n = readInt()
    for (i in 1..n) {
        println(if (solve(readLn(), readLn())) "YES" else "NO")
    }
}