import kotlin.math.*

fun solve() {
    val s = readLine()!!
    if ('>' !in s && '<' !in s) {
        println("=")
    } else if ('>' !in s) {
        println('<')
    } else if ('<' !in s) {
        println('>')
    } else {
        println('?')
    }
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}