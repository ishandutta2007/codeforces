fun gcd(x: Int, y: Int): Int = if (y > 0) gcd(y, x % y) else x

fun main(args: Array<String>) {
    val s = readLine()!!
    var a: Int = 0
    var b: Int = 0
    var c: Int = 0
    var state: Int = 0
    var d: Int = 0
    var pr: Int = 0
    for (ch in s) {
        when (ch) {
            '.' -> state = 1
            '(' -> state = 2
            ')' -> state = 3
            else -> {
                var x = ch.toInt() - '0'.toInt()
                when (state) {
                    0 -> a = a * 10 + x
                    1 -> {
                        b = b * 10 + x
                        pr++
                    }
                    2 -> {
                        c = c * 10 + x
                        d++
                    }
                }
            }
        }
    }

    var q = 1
    for (i in 1..d)
        q *= 10
    q--
    var deg = 1
    for (i in 1..pr)
        deg *= 10
    var p: Int = a * deg * q + b * q + c
    q *= deg
    val g = gcd(p, q)
    println("${p/g}/${q/g}")
}