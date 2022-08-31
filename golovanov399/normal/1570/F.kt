fun solve() {
    val (n, m) = readLine()!!.split(' ').map(String::toInt)
    val a = (0 until n).map { readLine()!!.split(' ').map(String::toInt) }
    val ans = (0 until n - 1).map { i ->
        (0 until m - 1).filter { j ->
            a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1] == 4
        }.map { j -> i to j }
    }.flatten()
    val b = MutableList(n) { MutableList(m) { 0 } }
    ans.forEach { (i, j) ->
        for (x in 0..1) {
            for (y in 0..1) {
                b[i + x][j + y] = 1
            }
        }
    }
    if (a != b) {
        println(-1)
    } else {
        println(ans.size)
        ans.forEach { (i, j) -> println("${i + 1} ${j + 1}") }
    }
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}