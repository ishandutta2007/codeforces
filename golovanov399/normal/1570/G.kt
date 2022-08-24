fun solve() {
    print("? ")
    println((0 until 100).joinToString(" "))
    val leftHalf = readLine()!!.toInt() and (127 shl 7)
    print("? ")
    println((28 until 128).map { it shl 7 }.joinToString(" "))
    val rightHalf = readLine()!!.toInt() and 127
    print("! ")
    println(leftHalf or rightHalf)
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}