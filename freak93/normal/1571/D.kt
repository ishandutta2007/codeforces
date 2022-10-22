import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    val (n, m) = readInts()

    var count = Array<IntArray>(n) { IntArray(n) }
    var first = IntArray(n)
    var last = IntArray(n)

    var (X, Y) = readInts()
    X -= 1
    Y -= 1
    count[X][Y] += 1
    first[X] = 1
    last[Y] = 1
    for (i in 2..m) {
        if (m == 1) {
            break
        }
        var (x, y) = readInts()
        x -= 1
        y -= 1
        count[x][y] += 1
        first[x] += 1
        last[y] += 1
    }

    var worst = 0
    for (x in 0..(n - 1)) {
        for (y in 0..(n - 1)) {
            if (x == y) continue
            val top = count[x][y]
            val mid = first[x] + last[y] - 2 * top
            
            val place = if (X == x && Y == y) {
                1
            } else if (X == x || Y == y) {
                top + 1
            } else {
                top + mid + 1
            }
            worst = max(worst, place)
        }
    }
    println(worst)
}