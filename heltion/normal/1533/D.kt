fun main() {
    fun readInt() = readLine()!!.toInt()
    fun readInts() = readLine()!!.split(' ').map { it.toInt() }
    val (n, m) = readInts()
    val s = Array(n){
        readLine()!!
    }.groupBy { it }
    repeat (readInt()) {
        val t = readLine()!!
        println(Array(m + 1){
            t.substring(0, it) + t.substring(it + 1)
        }.toSet().map {
            if (s.containsKey(it)) s[it]!!.size else 0}.sum()
        )
    }
}