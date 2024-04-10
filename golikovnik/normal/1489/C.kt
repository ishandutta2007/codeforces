/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */

fun main() {
    readLine()
    println(readLine()!!.split(Regex("[^x]")).sumOf { maxOf(0, it.length - 2) })
}