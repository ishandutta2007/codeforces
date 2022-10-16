import java.util.*
import kotlin.collections.ArrayList

fun solve() {
    val n = readInt()
    val divs = Array(n + 1) { ArrayList<Int>() }
    val muls = Array(n + 1) { ArrayList<Int>() }
    for (i in 1..n) {
        var j = i
        while (j <= n) {
            divs[j].add(i)
            muls[i].add(j)
            j += i
        }
    }
    data class Item(val i: Int, val add: Int) : Comparable<Item> {
        override fun compareTo(other: Item): Int {
            if (add == other.add) {
                return i.compareTo(other.i)
            }
            return -add.compareTo(other.add)
        }
    }
    val set = TreeSet<Item>()
    val add = IntArray(n + 1) { divs[it].size - 1 }
    for (i in 1..n) {
        set.add(Item(i, add[i]))
    }
    val answers = LongArray(n)
    var ans = 0L
    repeat(n) {
        val who = set.pollFirst()!!
        ans += who.add
        answers[it] = ans
        for (j in muls[who.i]) {
            val item = Item(j, add[j])
            val did = set.remove(item)
            add[j]--
            if (did) {
                set.add(Item(j, add[j]))
            }
        }
        for (j in divs[who.i]) {
            val item = Item(j, add[j])
            val did = set.remove(item)
            add[j]--
            if (did) {
                set.add(Item(j, add[j]))
            }
        }
    }
    println(answers.joinToString(" "))
}

fun main() {
//    repeat(readInt()) {
        solve()
//    }
}

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles