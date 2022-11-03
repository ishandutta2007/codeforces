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
        var str = readLn()
        var cnt1 = 0
        var cnt2 = 0
        for(c in str)
        {
            if(c == '>')
                cnt1 = 1
            if(c == '<')
                cnt2 = 1;
        }
        if(cnt1 > 0 && cnt2 > 0) println("?")
        else if(cnt1 > 0) println(">")
        else if(cnt2 > 0) println("<")
        else println("=")
    }
}