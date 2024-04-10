import java.io.BufferedReader
import kotlin.system.exitProcess

fun main() {
    val br = System.`in`.bufferedReader()
    val (n, t) = br.readLine().split(" ").map { it.toInt() }
    val saved = IntArray(n) { -1 }
    val converted = F719Fenwick(n)
    fun query(r: Int): Int {
        val check = saved[r]
        return if (check == -1) {
            println("? 1 ${r + 1}")
            val ans = br.readLine().toInt()
            if (ans == -1) exitProcess(0)
            saved[r] = ans - converted.get(r)
            ans
        } else {
            check + converted.get(r)
        }
    }

    fun answer(i: Int) {
        println("! ${i + 1}")

    }
    repeat(t) {
        val k = br.readLine().toInt()
        var high = n
        var low = 0
        var mid = (high + low) shr 1
        while (low < high) {
            val numZeros = mid + 1 - query(mid)
            if (numZeros >= k) {
                high = mid
            } else {
                low = mid + 1
            }
            mid = (high + low) shr 1
        }
        answer(mid)
        converted.add(mid, 1)
    }
}

private class F719Fenwick(val size: Int) {
    private val ary = IntArray(size)

    fun add(idx: Int, v: Int) {
        var k = idx + 1
        while (k <= size) {
            ary[k - 1] += v
            k += k and -k
        }
    }

    fun set(idx: Int, v: Int) {
        add(idx, v - get(idx, idx))
    }

    fun get(idx: Int): Int {
        var k = idx + 1
        var r = 0
        while (k > 0) {
            r += ary[k - 1]
            k -= k and -k
        }
        return r
    }

    fun get(a: Int, b: Int): Int {
        return get(b) - get(a - 1)
    }

    //returns the 0 indexed index of the largest prefix sum that does not exceed the given value
    fun prefixSearch(v: Int): Int {
        var idx = 0
        var curSum = 0
        var curBit = Integer.highestOneBit(size)
        while (curBit > 0) {
            if (curBit + idx <= size) {
                if (curSum + ary[curBit + idx - 1] <= v) {
                    curSum += ary[curBit + idx - 1]
                    idx += curBit
                }
            }
            curBit = curBit shr 1
        }
        return idx - 1
    }
}