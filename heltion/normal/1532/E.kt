fun main() {
    readLine()
    val a = readLine()!!.split(' ').map(String::toLong)
    val sum = a.sum()
    val g = a.groupingBy{it}.eachCount()
    val j = a.withIndex().filter{
        var result = false
        if ((sum - it.value) % 2 == 0L) {
            val half = (sum - it.value) / 2
            if (g.containsKey(half)) {
                if (it.value != half || g[half]!! >= 2) {
                    result = true
                }
            }
        }
        result
    }.map{
        it.index
    }
    println(j.size)
    j.forEach{
        print("${it + 1} ")
    }
}