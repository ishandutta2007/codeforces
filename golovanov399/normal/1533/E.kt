import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun lowerBound(a: List<Int>, x: Int): Int {
    val idx = a.binarySearch(x)
    return if (idx >= 0) idx else -1 - idx
}

const val inf = 2e9.toInt()

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt).sorted()
    val b = readLine()!!.split(' ').map(String::toInt).sorted()

    val pref = (0 until n).scan(-inf) { pr, i -> max(pr, b[i] - a[i]) }
    val suf = (0 until n).scan(-inf) { pr, i -> max(pr, b[n - i] - a[n - 1 - i]) }

    readLine()
    println(readLine()!!.split(' ').map(String::toInt).map { x ->
        val pos = lowerBound(a, x)
        maxOf(pref[pos], suf[n - pos], b[pos] - x)
    }.joinToString(" "))
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}