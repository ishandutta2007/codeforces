import kotlin.math.*

class SegTree(_a: List<Int>) {
    private val n = 1 shl (32 - (_a.size - 1).countLeadingZeroBits())
    var a = IntArray(2 * n) { Int.MAX_VALUE }

    init {
        for (i in _a.indices) {
            a[n + i] = _a[i]
        }
        for (i in n - 1 downTo 1) {
            a[i] = min(a[i + i], a[i + i + 1])
        }
    }

    fun change(_pos: Int, x: Int) {
        var pos = _pos + n
        a[pos] = x
        while (pos > 1) {
            pos /= 2
            a[pos] = min(a[pos + pos], a[pos + pos + 1])
        }
    }

    fun getLeftmostNoMoreThan(thres: Int): Int {
        if (a[1] > thres) {
            return -1
        }
        var (v, l, r) = listOf(1, 0, n)
        while (r > l + 1) {
            if (a[2 * v] <= thres) {
                r = (l + r) / 2
                v *= 2
            } else {
                l = (l + r) / 2
                v = v * 2 + 1
            }
        }
        return l
    }
}

fun solve() {
    val (n, m, k) = readLine()!!.split(' ').map(String::toInt)
    val a = readLine()!!.split(' ').map(String::toInt)

    fun check(from: Int): Boolean {
        var rem = m
        var cur = 0
        for (i in from until n) {
            if (a[i] > cur) {
                if (rem == 0) {
                    return false
                }
                rem -= 1
                cur = k
            }
            cur -= a[i]
        }
        return true
    }

    var l = -1
    var r = n
    while (r > l + 1) {
        val mid = (l + r) / 2
        if (check(mid)) {
            r = mid
        } else {
            l = mid
        }
    }
    println(n - r)
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}