/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */

fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map { it.toInt() }.reversed()
    val ans = mutableListOf<Int>()
    a.forEach { if (it !in ans) ans.add(it) }
    println(ans.size)
    println(ans.reversed().joinToString(" "))
}