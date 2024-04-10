import kotlin.math.min

fun main() {
    val (n, m, k) = readLine()!!.split(' ').map(String::toInt)
    val a = readLine()!!.split(' ').map(String::toLong).sorted().toLongArray()
    var sums_list = mutableListOf<Long>()
    sums_list.add(0)
    for (l in a) {
        sums_list.add(sums_list.last() + l)
    }
    val sums = sums_list.toLongArray()

    var ans = sums.last()
    for (i in 0..(n-m)) {
        var l = i
        var r = i + (m - 1) / 2
        if (a[r] * ((m + 1) / 2) - (sums[r + 1] - sums[i]) <= k) {
            ans = min(ans, a[r] * ((m + 1) / 2) - (sums[r + 1] - sums[i]) + (sums[i + m] - sums[r + 1]) - a[r] * (m / 2))
            continue
        }

        while (r > l + 1) {
            val mid = (l + r) / 2
            if (a[mid] * (mid - i) - (sums[mid] - sums[i]) <= k) {
                l = mid;
            } else {
                r = mid;
            }
        }
        var thres = a[l] + (k - (a[l] * (l - i) - (sums[l] - sums[i]))) / (l - i + 1);
        ans = min(ans, thres * (l - i + 1) - (sums[l + 1] - sums[i]) + (sums[i + m] - sums[r]) - thres * (i + m - r))
    }

    println(ans)
}