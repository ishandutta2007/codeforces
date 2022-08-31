private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

fun biggestSaw(A_: List<Int>) : List<Int> {
    val A = A_.sorted()
    fun getSaw(len: Int): List<Int> {
        val l = mutableListOf<Int>()
        // take big then small
        for (i in 0..len-1) {
            if (i % 2 == 0) {
                l += A[A.size - (len - len / 2) + (i / 2)]
            } else {
                l += A[i / 2]
            }
        }
        return l
    }

    fun isSaw(a: List<Int>): Boolean {
        for (i in 0..a.size-2) {
            if (a[i] == a[i + 1]) return false
            if (i % 2 == 0) {
                if (!(a[i] > a[i+1])) {
                    return false
                }
            } else {
                if (!(a[i] < a[i+1])) {
                    return false
                }
            }
        }
        return true
    }

    var mi = 0
    var ma = A.size + 1

    while (ma - mi > 1) {
        val md = (mi + ma) / 2
        val s = getSaw(md)
        if (isSaw(s)) {
            mi = md
        } else {
            ma = md
        }
    }

    return getSaw(mi)
}

fun main() {
    val T = readInt()
    for (t in 1..T) {
        val N = readInt()
        val A = readInts()

        val lpos = biggestSaw(A)
        val lneg = biggestSaw(A.map({-it})).map({-it})

        val l = if (lpos.size >= lneg.size) lpos else lneg
        outputLn("${l.size}")
        outputLn("${l.joinToString(" ")}")
    }
    println(OUTPUT_LINES.joinToString("\n"))
}