fun main() {
    val n = readLine()!!.toInt()
    fun query(a: Int): Int {
        println("? $a")
        return readLine()!!.toInt()
    }

    var low = 2 * n - 1
    var high = 2001 * n - 1
    while (low < high) {
        val mid = (low + high) shr 1
        val check = query(mid)
        if (check == 1) {
            high = mid
        } else {
            low = mid + 1
        }
    }
    val lSum = high - (n - 1)
    var ans = high
    for (rows in 2..n) {
        val totalChars = lSum + (n - rows)
        val widthNeeded = (totalChars - 1) / rows + 1
        if (widthNeeded * rows < ans && query(widthNeeded) == rows) {
            ans = widthNeeded * rows
        }
    }
    println("! $ans")
}