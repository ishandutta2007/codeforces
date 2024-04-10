
fun solve() {
    val (n, k) = readInts()
    val s = readLn()
    val st = ArrayList<Char>()
    var curK = k
    var ans = 0
    for (ch in s) {
        when (ch) {
            '(' -> st.add(ch)
            else -> {
                if (curK > 0 && st.size >= 2 && st[st.size - 2] == '(') {
                    st.removeAt(st.size - 1)
                    curK--
                    ans++
                } else {
                    st.add(ch)
                }
            }
        }
    }
    var bal = 0
    for (ch in st) {
        when {
            ch == '(' -> bal++
            else -> {
                bal--
                if (bal == 0) {
                    ans++
                }
            }
        }
    }
    println(ans)
}

fun main() {
    repeat(readInt()) {
        solve()
    }
}

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles