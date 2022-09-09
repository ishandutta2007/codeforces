fun main() {
    fun readInt() = readLine()!!.toInt()
    fun readInts() = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
    repeat(readInt()) {
        val n = readInt()
        val (a, va) = readInts()
        val (c, vc) = readInts()
        val b = readInt()
        for(vb in va..vc)
            if (vb - va <= b - a && vc - vb <= c - b) {
                println(vb)
                break
            }
    }
}