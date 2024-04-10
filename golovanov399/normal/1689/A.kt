fun solve() {
    val (n, m, k) = readLine()!!.split(' ').map(String::toInt)
    val a = (0..1).map {
        readLine()!!.toList().sorted().joinToString("")
    }
    var i = -1
    var last = 0
    var ans = ""
    val res = mutableListOf(0, 0)
    while (res[0] < a[0].length && res[1] < a[1].length) {
        var j = (0..1).minByOrNull { j -> a[j][res[j]] }!!
        if (j == i && last == k) {
            j = j xor 1
        }
        if (i != j) {
            last = 0
        }
        i = j
        last += 1
        ans += a[j][res[j]]
        res[j] += 1
    }
    println(ans)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}