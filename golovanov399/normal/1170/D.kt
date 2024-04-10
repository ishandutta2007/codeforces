fun main() {
    val m = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt).toIntArray()
    val n = a.count {it == -1}
    var ans = Array(n) { mutableListOf<Int>() }
    var j = 0
    var remaining = mutableSetOf<Int>()
    for (i in 0 until n) {
        remaining.add(i)
    }
    while (j < m) {
        var to_erase = mutableListOf<Int>()
        for (i in remaining) {
            if (a[j] == -1) {
                to_erase.add(i)
            } else {
                ans[i].add(a[j])
            }
            j += 1
        }
        for (i in to_erase) {
            remaining.remove(i)
        }
    }
    println(ans.size)
    for (v in ans) {
        print(v.size)
        for (x in v) {
            print(" $x")
        }
        println()
    }
}