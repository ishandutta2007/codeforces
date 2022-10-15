/**
 * Created by ezhang on 5/28/19.
 */

import java.util.LinkedList;

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

fun <T> linkedListOf(vararg items: T) = LinkedList<T>().apply {
    for (i in items) { add(i) }
}

fun main(args : Array<String>) {
    val n = readInt()
    val ar = readInts()
    val k = ar.count({it == -1})
    println(k)
    var ans = Array<MutableList<Int>>(k){ mutableListOf() };
    var use = linkedListOf(0);
    for (i in 1..k-1)
        use.add(i)
    for (i in 0..n-1) {
        var idx = use.remove()!!;
        if (ar[i] != -1) {
            ans[idx].add(ar[i]);
            use.add(idx);
        }
    }
    for (i in 0..k-1) {
        println("${ans[i].size} ${ans[i].joinToString(" ")}")
    }
}