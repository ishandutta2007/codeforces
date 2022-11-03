import java.util.*
import kotlin.Comparator

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun main() {
    var ncase = readInt()
    repeat(ncase)
    {
        var (n, k) = readLongs()
        var str = readLn()
        var ans = 0
        var o = 0
        for (c in str) {
            if (c == '(') o++
            else {
                o--;
                if (o == 0) ans++
                else if (k > 0) {
                    ans++;
                    k--;
                }
            }
        }
        println(ans)
    }
}