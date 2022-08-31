import java.util.*
import kotlin.math.*

class SegTree(_n: Int) {
    val n = 1 shl (32 - (_n - 1).countLeadingZeroBits())
    var a = MutableList(n + n) { if (it == 0 || (it * (n shr (31 - it.countLeadingZeroBits()))) < n + _n) 0 else 1_000_000_000 }

    fun add(pos: Int, x: Int) {
        var v = pos + n
        a[v] += x
        while (v > 1) {
            v /= 2
            a[v] = min(a[v + v], a[v + v + 1])
        }
    }

    fun getMin(): Int {
        return a[1]
    }
}

val N = 202_202
val mod = 1_000_000_007

fun solve() {
    val (n, q) = readLine()!!.split(' ').map(String::toInt)
    var erat = IntArray(N) { 1 }
    var primes = mutableListOf<Int>()
    for (i in 2 until N) {
        if (erat[i] == 1) {
            erat[i] = i
            primes.add(i)
        }
        for (p in primes) {
            if (p > erat[i] || p * i >= N) {
                break
            }
            erat[i * p] = p
        }
    }
    val sz = primes.size

    var pidx = IntArray(N) { 0 }
    for (i in 0 until sz) {
        pidx[primes[i]] = i
    }

    val a = readLine()!!.split(' ').map(String::toInt)
    var occurred_positions = MutableList(sz) { TreeSet<Int>() }
    for (i in 0 until n) {
        var x = a[i]
        while (x > 1) {
            val p = erat[x]
            occurred_positions[pidx[p]].add(i)
            x /= p
        }
    }

    val qrs = List(q) {
        val s = readLine()!!.split(' ').map(String::toInt)
        Pair(s[0] - 1, s[1])
    }

    for ((i, y) in qrs) {
        var x = y
        while (x > 1) {
            val p = erat[x]
            occurred_positions[pidx[p]].add(i)
            x /= p
        }
    }

    val good_primes = BooleanArray(sz) { occurred_positions[it].size == n }
    val all_good_primes = (0 until sz).filter { good_primes[it] }.toIntArray()
    val cnt = all_good_primes.size
    var trees = MutableList(cnt) { SegTree(n) }

    var nidx = IntArray(sz) { 0 }
    for (i in 0 until cnt) {
        nidx[all_good_primes[i]] = i
    }

    var ans = 1L
    for (i in 0 until n) {
        var x = a[i]
        while (x > 1) {
            val p = erat[x]
            if (good_primes[pidx[p]]) {
                val old = trees[nidx[pidx[p]]].getMin()
                trees[nidx[pidx[p]]].add(i, 1)
                if (old < trees[nidx[pidx[p]]].getMin()) {
                    ans = ans * p % mod
                }
            }
            x /= p
        }
    }

//    for (t in trees) {
//        println(t.a.joinToString())
//    }

    var answer = mutableListOf<Long>()
    for ((i, y) in qrs) {
        var x = y
        while (x > 1) {
            val p = erat[x]
            if (good_primes[pidx[p]]) {
                val old = trees[nidx[pidx[p]]].getMin()
                trees[nidx[pidx[p]]].add(i, 1)
                if (old < trees[nidx[pidx[p]]].getMin()) {
                    ans = ans * p % mod
                }
            }
            x /= p
        }
        answer.add(ans)
    }

    println(answer.joinToString("\n"))
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}