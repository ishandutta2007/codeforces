fun main(args: Array<String>) {
    val (q) = readLine()!!.split(' ').map(String::toInt)
    for (i in 0..(q - 1)) {
        val (x, y) = readLine()!!.split(' ').map(String::toInt)
        var a = 0
        var b = 0
        var c = 0
        if (x > y) {
            a = y - 1
            b = 1
            c = x - y + 1
        } else {
            a = x - 1
            b = 1
            c = y - x + 1
        }
        println("$a $b $c")
    }
}