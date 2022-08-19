private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

fun go() {
    val n = readInt()
    val inds = mutableMapOf<Int, MutableList<Int>>()
    readInts().forEachIndexed {
        ind, a -> inds.getOrPut(a, {mutableListOf<Int>()}).add(ind)
    }

    val colors = MutableList<Char>(n, {'B'})
    // two bit's
    val redCnts = MutableList<Int>(n, {0})
    val greenCnts = MutableList<Int>(n, {0})

    val query = { ind: Int, l: List<Int> ->
        var a = ind+1
        var ans = 0
        while (a > 0) {
            ans += l[a-1]
            a -= (a and (-a))
        }
        ans
    }
    val update = { ind: Int, l: MutableList<Int> ->
        var a = ind+1
        while (a <= n) {
            l[a-1] ++
            a += (a and (-a))
        }
    }

    for (v in 1..n) {
        if (v in inds) {
            val a = inds[v]!!
            if (a.size == 2) {
                if (query(a[0], redCnts) == query(a[1], greenCnts)) {
                    update(a[0], redCnts)
                    update(a[1], greenCnts)
                    colors[a[0]] = 'R'
                    colors[a[1]] = 'G'
                    continue
                }
            }
        }
        break
    }
    outputLn(colors.joinToString(""))
}

fun main() {
    go()
    println(OUTPUT_LINES.joinToString("\n"))
}