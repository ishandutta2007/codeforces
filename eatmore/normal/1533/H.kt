import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*
import kotlin.experimental.and

fun solve() {
    val n = scanInt()
    val m = scanInt()
    val v = Array(n) { ByteArray(m) }
    for (i in 0 until n) {
        val s = scanString()
        for (j in 0 until m) {
            v[i][j] = (1 shl s[j] - 'A').toByte()
        }
    }
    val ans = LongArray(32)
    val d = IntArray(m)
    val stack = IntArray(2 * m)
    for (s in 1..31) {
        Arrays.fill(d, 0)
        var cans: Long = 0
        for (i in n - 1 downTo 0) {
            for (j in 0 until m) {
                d[j] = if ((v[i][j].toInt() and s) != v[i][j].toInt()) 0 else d[j] + 1
            }
            var stackSize = 0
            for (j in 0 until m) {
                while (stackSize > 0 && d[stack[stackSize - 1]] > d[j]) {
                    stackSize -= 2
                    cans += d[stack[stackSize + 1]].toLong() * (stack[stackSize + 1] - stack[stackSize] + 1) * (j - stack[stackSize + 1])
                }
                stack[stackSize] = if (stackSize == 0) 0 else stack[stackSize - 1] + 1
                stack[stackSize + 1] = j
                stackSize += 2
            }
            while (stackSize > 0) {
                stackSize -= 2
                cans += d[stack[stackSize + 1]].toLong() * (stack[stackSize + 1] - stack[stackSize] + 1) * (m - stack[stackSize + 1])
            }
        }
        ans[s] = cans
    }
    for (i in 0..4) {
        for (j in 0..31) {
            if (j and (1 shl i) == 0) {
                ans[j or (1 shl i)] -= ans[j]
            }
        }
    }
    val theAns = LongArray(5)
    for (i in 1..31) {
        theAns[Integer.bitCount(i) - 1] += ans[i]
    }
    for (i in 0..4) {
        out.print(theAns[i].toString() + " ")
    }
}

fun scanInt(): Int {
    return scanString().toInt()
}

fun scanLong(): Long {
    return scanString().toLong()
}

fun scanString(): String {
    var t = tok
    while (t == null || !t.hasMoreTokens()) {
        t = StringTokenizer(inp.readLine())
        tok = t
    }
    return t.nextToken()
}

val inp = BufferedReader(InputStreamReader(System.`in`))
val out = PrintWriter(System.out)
var tok: StringTokenizer? = null
fun main() {
    solve()
    inp.close()
    out.close()
}