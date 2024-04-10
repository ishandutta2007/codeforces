fun main() {
    val (n, m) = readLine()!!.split(' ').map(String::toInt)
    val a = readLine()!!.split(' ').map(String::toInt).toIntArray()
    var sums_list = mutableListOf<Int>()
    sums_list.add(0)
    for (l in a) {
        sums_list.add(sums_list.last() + l)
    }
    val sums = sums_list.toIntArray()

    val q = readLine()!!.toInt()
    for (tc in 1..q) {
        val positions = readLine()!!.split(' ').drop(1).map(String::toInt).toIntArray()
        var idx = 0
        var last = 0
        for (pos in positions) {
            val len = pos - last - 1
            var l = idx
            var r = n + 1
            while (r > l + 1) {
                val mid = (l + r) / 2
                if (sums[mid] - sums[idx] <= len) {
                    l = mid
                } else {
                    r = mid
                }
            }
            idx = l

            last = pos
        }
        println(if (sums[a.size] - sums[idx] <= m - last) "YES" else "NO")
    }
}