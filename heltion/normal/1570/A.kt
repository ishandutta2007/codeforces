fun main() {
    fun readInt() = readLine()!!.toInt()
    fun readInts() = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
    repeat(readLine()!!.toInt()) {
        println(readInts().sum())
    }
}