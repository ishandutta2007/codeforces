import kotlin.math.max
import kotlin.math.min

fun main() {
    val t = readLine()!!.toInt()
    for (i in 1..t) {
        solve()
    }
}

fun solve() {
    val n = readLine()!!.toInt()
    var a = readLine()!!.split(' ').map(String::toInt).sorted()

    var max_cnt = 0
    var cnt = 0
    var last = 0
    for (x in a) {
        if (x == last) {
            cnt += 1
        } else {
            last = x
            cnt = 1
        }
        max_cnt = max(max_cnt, cnt)
    }
    var optional_answer = mutableListOf<Int>()
    if (max_cnt > n / 2) {
        val ar = a.toIntArray()
        var idx = n / 2
        while (idx < n && ar[idx] == ar[n / 2]) {
            idx += 1
        }
        optional_answer.add(ar[n / 2])
        while (idx < n) {
            optional_answer.add(ar[idx])
            optional_answer.add(ar[n / 2])
            idx += 1
        }

        var tmp = mutableListOf<Int>()
        idx = n / 2
        while (idx >= 0 && ar[idx] == ar[n / 2]) {
            idx -= 1
        }
        tmp.add(ar[n / 2])
        while (idx >= 0) {
            tmp.add(ar[idx])
            tmp.add(ar[n / 2])
            idx -= 1
        }
        if (tmp.size > optional_answer.size) {
            optional_answer = tmp
        }
        max_cnt = n - max_cnt
    }
    max_cnt = min(max_cnt, (n + 1) / 2)
    var new_a = mutableListOf<Int>()
    cnt = 0
    last = 0
    for (x in a) {
        if (x == last) {
            cnt += 1
        } else {
            last = x
            cnt = 1
        }
        if (cnt <= max_cnt) {
            new_a.add(x)
        }
    }

    val res = new_a.toIntArray()
    if (optional_answer.size > res.size) {
        println(optional_answer.size)
        println(optional_answer.joinToString(prefix = "", postfix = "", separator = " "))
        return
    }
    var r = new_a.size / 2
    var l = 0
    println(new_a.size)
    while (r < new_a.size) {
        print("${res[r]} ")
        if (l < new_a.size / 2) {
            print("${res[l]} ")
        }
        l += 1
        r += 1
    }
    println()
}