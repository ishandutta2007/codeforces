fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt)
    var p = Array<Int>(n, {i -> 0})
    var used = Array<Boolean>(n, {i -> false})
    for (i in 1..n){
        var j = 0
        while (used[j] || a[j] > p[j])
            j++
        print("${j + 1} ")
        used[j] = true
        j--
        while (j >= 0){
            if (used[j] == false)
                p[j] += 1
            j--
        }
    }
    println()
}