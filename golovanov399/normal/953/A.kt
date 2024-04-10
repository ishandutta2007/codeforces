fun main(args: Array<String>) {
    val (l, r) = readLine()!!.split(' ').map(String::toLong)
    var ans = 0

    var x: Long = 1
    for (i in 0..100) {
        var y: Long = 1
        for (j in 0..100) {
            if (x * y >= l && x * y <= r) {
                ans += 1
            }
            y *= 3
            if (x * y > r) {
                break
            }
        }
        x *= 2
        if (x > r) {
            break
        }
    }
    println("$ans")

    /*
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
    */
}