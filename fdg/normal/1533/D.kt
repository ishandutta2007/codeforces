import java.lang.Integer.max

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

private fun hash(s: String): Long {
    return s.fold(0.toLong()) { r, c -> r * 27 + (c - 'a').toLong() }
}

fun main(args: Array<String>) {
    val (n, m) = readInts()
    val f = (1..n).associateBy { hash(readLn()) }

    var q = readInt()
    println((1..q).map {
        var used = setOf<Int>().toMutableSet()
        var str = readLn()
        for (i in 1..str.length) {
            var th = 0.toLong()
            for (j in 1..str.length) {
                if (i != j) th = th * 27 + (str[j - 1] - 'a')
            }
            val index = f[th]
            if (index != null)
                used.add(index)
        }
        used.size
    }.joinToString("\n"))
}