fun main(args: Array<String>) {
    var n = readLine()!!.toInt()
    var s = Array(n, {""})
    for (i in 0 until n) {
        s[i] = readLine()!!
    }
    s.sortBy { it.length }
    for (i in 1 until n) {
        if (!s[i].contains(s[i - 1])) {
            println("NO")
            return
        }
    }
    println("YES")
    s.forEach {
        println(it)
    }
}