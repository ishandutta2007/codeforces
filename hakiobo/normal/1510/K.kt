import java.io.PrintWriter
import java.util.*

fun main() = tm {
    val n = readInt()
    var arr = readIntArray(2*n)
    val cpy = arr.copyOf()

    var countOne = 0
    var countTwo = 0
    var found = false

    if (check(arr)) println(0)
    else {
        for (i in arr.indices) {
            arr = if (i % 2 == 0) {
                opOne(arr)
            } else {
                opTwo(arr)
            }
            countOne++
            if (check(arr)) {
                found = true
                break
            }
        }

        cpy.copyInto(arr)
        for (i in arr.indices) {
            arr = if (i % 2 == 0) {
                opTwo(arr)
            } else {
                opOne(arr)
            }
            countTwo++
            if (check(arr)) {
                found = true
                break
            }
        }

        if (found) {
            println(minOf(countOne, countTwo))
        } else {
            println(-1)
        }
    }

}

fun opOne(arr: IntArray) : IntArray {
    for (i in 0 until arr.size - 1 step 2) {
        arr[i] = arr[i+1].also {arr[i+1] = arr[i]}
    }
    return arr
}

fun opTwo(arr: IntArray) : IntArray {
    val new = IntArray(arr.size)

    for (i in 0 until arr.size / 2) {
        new[i] = arr[arr.size / 2 + i]
    }

    for (i in 0 until arr.size / 2) {
        new[arr.size / 2 + i] = arr[i]
    }

    return new
}

fun check(arr: IntArray) : Boolean {
    for (i in 1 until arr.size) {
        if (arr[i] < arr[i-1]) {
            return false
        }
    }

    return true
}

private inline fun <T> tm(block: KingsTaskIO.() -> T) {
    itm(block)
}

private lateinit var Templateio: KingsTaskIO
private var refs = 0
private inline fun <T> itm(block: KingsTaskIO.() -> T): T {
    if (refs++ == 0) {
        Locale.setDefault(Locale.US)
        Templateio = KingsTaskIO()
    }
    val ret = block(Templateio)
    if (--refs == 0) {
        Templateio.close()
    }
    return ret
}

private class KingsTaskIO : PrintWriter(System.out.bufferedWriter(), false) {
    private val r = System.`in`.bufferedReader()
    private var tk = StringTokenizer("")

    fun readWord(): String {
        while (!tk.hasMoreTokens()) {
            tk = StringTokenizer(r.readLine() ?: return "", " ")
        }
        return tk.nextToken()
    }

    fun clearLine() { tk = StringTokenizer("") }
    fun readLine() = r.readLine()
    fun readInt() = readWord().toInt()
    fun readDouble() = readWord().toDouble()
    fun readLong() = readWord().toLong()

    fun readIntArray(n: Int = readInt()) = IntArray(n) { readInt() }
    fun readLongArray(n: Int = readInt()) = LongArray(n) { readLong() }
    fun readDoubleArray(n: Int = readInt()) = DoubleArray(n) { readDouble() }
}