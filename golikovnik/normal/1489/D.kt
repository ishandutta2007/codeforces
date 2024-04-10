/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */

fun main() {
    val n = readLine()!!.toInt()
    val a = List(n) { readLine()!! }.sortedBy { it.length }
    if (!a.zipWithNext().all { it.first in it.second }) {
        println("NO")
        return
    }
    println("YES")
    println(a.joinToString("\n"))
}