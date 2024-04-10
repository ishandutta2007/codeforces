fun main() {
    val n = readLine()!!.toInt()
    var inp = readLine()!!.split(' ').map(String::toInt).toIntArray()
    var a = Array(n) {
        Pair(inp[it], it)
    }
    a.sortWith(compareBy({-it.first}, {-it.second}))

    var f = Array(n, {0})
    var ans = 0
    for ((_, i) in a) {
        var j = i
        var x = 0
        while (j >= 0) {
            x += f[j]
            j = (j and (j + 1)) - 1
        }
        if (x >= 2) {
            ans += 1
        }
        j = i
        while (j < n) {
            f[j] += 1
            j = j or (j + 1)
        }
    }

    println(ans)
}