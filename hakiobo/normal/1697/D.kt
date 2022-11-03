fun main() {
    val n = readLine()!!.toInt()
    var lastOccOf = IntArray(26) { -1 }
    val ans = CharArray(n)
    var distinctSoFar = 0

    val data = mutableListOf<Pair<Char, Int>>()
    for (i in 0 until n) {
        var low = 0
        var high = data.size
        while (low < high) {
            val mid = (low + high) shr 1
            println("? 2 ${data[mid].second + 1} ${i + 1}")
            val unique = readLine()!!.toInt()
            if (unique == data.size - mid + 1) { // not one of those letters
                high = mid
            } else {
                low = mid + 1
            }
        }
        ans[i] = if (high == 0) {
            println("? 1 ${i + 1}")
            readLine()!![0]
        } else {
            data.removeAt(high - 1).first
        }
        data += ans[i] to i

    }

    println("! ${ans.joinToString("")}")

}