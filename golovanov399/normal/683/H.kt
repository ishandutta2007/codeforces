fun main(args: Array<String>) {
    val (n, k) = readLine()!!.split(' ').map(String::toLong)
    val b = readLine()!!.split(' ').map(String::toInt)
    var a = Array<Int>(n.toInt(), {i -> 0})
    for (i in 1..n.toInt()) {
        a[b[i - 1] - 1] = i
    }
    var used = Array<Boolean>(n.toInt(), {i -> false})
    var ans = Array<Int>(n.toInt(), {i -> 0})
    for (i in 0..n.toInt() - 1) {
        if (used[i])
            continue
        var len = 0
        var j = i
        do {
            j = a[j] - 1
            len++
        } while (j != i)
        var kk = k % len
        while (kk > 0) {
            kk--
            j = a[j] - 1
        }
        var ii = i
        while (!used[ii]) {
            ans[ii] = j + 1
            used[ii] = true
            ii = a[ii] - 1
            j = a[j] - 1
        }
    }
    for (x in ans)
        print("$x ")
    println()
}