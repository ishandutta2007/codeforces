fun main(args: Array<String>) {
    var q = readLine()!!.toInt()
    repeat(q) {
        var (n, a, b) = readLine()!!.split(" ").map{ it.toLong() }
        if (b > a * 2) b = a * 2
        var ans = b * (n / 2)
        if (n % 2 == 1L) ans += a
        println(ans)
    }
}