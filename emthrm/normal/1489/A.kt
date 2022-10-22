fun main(args: Array<String>) {
    readLine()
    var a = readLine()!!.split(" ").map{ it.toInt() }.reversed().distinct().reversed()
    println(a.size)
    println(a.joinToString(" "))
}