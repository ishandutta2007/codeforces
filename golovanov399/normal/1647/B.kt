import kotlin.math.*

fun solve() {
    val (n, m) = readLine()!!.split(' ').map(String::toInt)
    val a = (0 until n).map { readLine()!! }
    fun isLeftmost(i: Int, j: Int): Boolean {
        return a[i][j] == '1' && (j == 0 || a[i][j - 1] == '0')
    }
    fun isTopmost(i: Int, j: Int): Boolean {
        return a[i][j] == '1' && (i == 0 || a[i - 1][j] == '0')
    }
    fun isRightmost(i: Int, j: Int): Boolean {
        return a[i][j] == '1' && (j == m - 1 || a[i][j + 1] == '0')
    }
    fun isBottommost(i: Int, j: Int): Boolean {
        return a[i][j] == '1' && (i == n - 1 || a[i + 1][j] == '0')
    }
    for (i in 0 until n) {
        for (j in 0 until m) {
            if (!isLeftmost(i, j) || !isTopmost(i, j)) {
                continue
            }
            var ii = i
            var jj = j
            while (ii < n && isLeftmost(ii, j)) {
                ++ii
            }
            --ii
            while (jj < m && isTopmost(i, jj)) {
                ++jj
            }
            --jj
            for (x in i..ii) {
                for (y in j..jj) {
                    if (a[x][y] == '0') {
                        println("No")
                        return
                    }
                }
            }
            for (x in i..ii) {
                if (!isRightmost(x, jj)) {
                    println("No")
                    return
                }
            }
            for (y in j..jj) {
                if (!isBottommost(ii, y)) {
                    println("No")
                    return
                }
            }
        }
    }
    println("Yes")
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}