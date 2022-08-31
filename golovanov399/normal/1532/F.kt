import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val n = readLine()!!.toInt()
    val a = (0 until 2 * n - 2).map { readLine()!! }.withIndex().sortedBy { (_, s) -> s.length }

    fun check(s: String) {
        val ans = CharArray(a.size)
        a.chunked(2).forEach { l ->
            run hack@{
                (0..2).forEach {
                    if (it == 2) {
                        return
                    }
                    if (s.startsWith(l[it].value) && s.endsWith(l[it xor 1].value)) {
                        ans[l[it].index] = 'P'
                        ans[l[it xor 1].index] = 'S'
                        return@hack
                    }
                }
            }
        }
        println(ans.joinToString(""))
        exitProcess(0)
    }

    val ss = a.takeLast(2).map { it.value }
    (0..1).forEach {
        if (ss[it].drop(1) == ss[it xor 1].dropLast(1)) {
            check(ss[it] + ss[it xor 1].last())
        }
    }
    exitProcess(1)
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}