fun main() {
    var n = readLine()!!.toInt()
    var s = readLine()!!.toCharArray()
    var f = readLine()!!.split(" ").map {it.toInt()}

    for (i in 0..(n - 1)) {
        var p: Int = s[i] - '0'
        if (p < f[p - 1]) {
            for (j in i..(n - 1)) {
                var q: Int = s[j] - '0'

                if (q > f[q - 1]) break

                s[j] = '0' + f[q - 1];
            }

            break
        }
    }

    println(s)
}