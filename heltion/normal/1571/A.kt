fun main() {
    fun readInt() = readLine()!!.toInt()
    fun readInts() = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
    repeat(readInt()) {
        val s = readLine()!!
        when {
            s.count{it == '='} == s.length -> println('=')
            s.count{it == '<'} == 0 -> println('>')
            s.count{it == '>'} == 0 -> println('<')
            else -> println('?')
        }
    }
}