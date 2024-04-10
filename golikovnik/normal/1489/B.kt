/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */

fun main() {
    repeat (readLine()!!.toInt()) {
        var (n, a, b) = readLine()!!.split(" ").map { it.toLong() }
        b = minOf(b, 2 * a)
        println(b * (n / 2) + a * (n % 2))
    }
}