fun main(args: Array<String>) {
    var (n, m, k) = readLine()!!.split(" ").map{ it.toInt() }
    var a = readLine()!!.split(" ").map{ it.toInt() }
    var size = k
    --m
    a.reversed().forEachIndexed { index, value ->
        if (value > k) {
            println(index)
            return
        }
        if (value > size) {
            if (m == 0) {
                println(index)
                return
            }
            --m
            size = k
        }
        size -= value
    }
    println(n)
}