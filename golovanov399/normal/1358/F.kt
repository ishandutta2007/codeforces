import kotlin.math.*

fun isStrictlySorted(a: LongArray): Boolean {
    for (i in 1 until a.size) {
        if (a[i] <= a[i - 1]) {
            return false
        }
    }
    return true
}

fun getCount(a: List<Long>, _b: List<Long>): Long {
    var b = _b.toLongArray()
    var ans = 0L
    var sum = a.sum()
    while (b.sum() > sum) {
        if (!isStrictlySorted(b)) {
            b = b.reversedArray()
        }
        if (!isStrictlySorted(b)) {
            return -1L
        }
        if (a.size == 2) {
            if (a[0] + a[1] <= b[0] + b[1] % b[0]) {
                ans += b[1] / b[0]
                b[1] %= b[0]
                if (b[1] == 0L) {
                    return -1L
                }
            } else if ((b[0] + b[1] - a[0] - a[1]) % b[0] != 0L) {
                return -1L
            } else {
                val tmp = (b[0] + b[1] - a[0] - a[1]) / b[0]
                ans += tmp
                b[1] -= tmp * b[0]
            }
        } else {
            ans += 1
            for (i in b.size - 1 downTo 1) {
                b[i] -= b[i - 1]
            }
        }
    }
    if (!a.toLongArray().contentEquals(b)) {
        b = b.reversedArray()
    }
    return if (!a.toLongArray().contentEquals(b)) {
        -1L
    } else {
        ans
    }
}

fun getString(a: List<Long>, _b: List<Long>): String {
    var b = _b.toLongArray()
    var result = mutableListOf<Char>()
    var sum = a.sum()
    while (b.sum() > sum) {
        if (!isStrictlySorted(b)) {
            b = b.reversedArray()
            result.add('R')
        }
        result.add('P')
        for (i in b.size - 1 downTo 1) {
            b[i] -= b[i - 1]
        }
    }
    if (!a.toLongArray().contentEquals(b)) {
        result.add('R')
    }
    return result.reversed().joinToString("")
}

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toLong)
    val b = readLine()!!.split(' ').map(String::toLong)
    if (n == 1) {
        if (a[0] == b[0]) {
            println("SMALL")
            println(0)
            println()
        } else {
            println("IMPOSSIBLE")
        }
        return
    }
    val ans = getCount(a, b)
    if (ans == -1L) {
        println("IMPOSSIBLE")
        return
    }
    if (ans > 200_000) {
        println("BIG")
        println(ans)
        return
    }
    println("SMALL")
    val res = getString(a, b)
    println(res.length)
    println(res)
}

fun main() {
    val t = 1; // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}