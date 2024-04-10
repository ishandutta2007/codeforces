/**
 * We declare a package-level function main which returns Unit and takes
 * an Array of strings as a parameter. Note that semicolons are optional.
 */

fun solve(a: Array<Int>, s: Array<String>): Unit {
    val n = a.size
    var i = 0
    while (i < n) {
        var j = 0
        while (j < i) {
            if (a[j] > a[i]) {
                var x = a[i]
                a[i] = a[j]
                a[j] = x
                var y = s[i]
                s[i] = s[j]
                s[j] = y
            }
            j++
        }
        i++
    }
    for (i in 0..n-1) {
        println(s[i])
    }
}

fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    var a = Array<Int>(n, {i -> 0})
    var s = Array<String>(n, {i -> ""})
    for (i in 0..n-1) {
        val x = readLine()!!.split(' ')
        a[i] = x[1].toInt()
        s[i] = x[0]
    }
    solve(a, s)
}