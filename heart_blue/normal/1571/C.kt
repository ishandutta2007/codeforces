private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles


fun main() {
    var ncase = readInt()
    while (ncase-- > 0) {
        var n = readInt()
        var l = 0
        var r = 1000000000
        while (n-- > 0) {
            var (str1, str2, str3) = readStrings()
            var k = str3.toInt()
            var minv = Math.min(str1.length, str2.length)
            str1 = str1.reversed()
            str2 = str2.reversed()
            var cnt = 0
            for (i in 0 until minv) {
                if (str1[i] == str2[i]) {
                    cnt++
                } else
                    break
            }
            var kl = 0
            var kr = 0
            if (k == 1) {
                kl = 0
                kr = cnt
            } else {
                kl = cnt + 1
                kr = r
            }
            l = Math.max(l, kl)
            r = Math.min(r, kr)
        }
        if (l > r) {
            println(0)
            println("")
        } else {
            println(r - l + 1)
            println((l..r).joinToString(" "))
        }
    }
}