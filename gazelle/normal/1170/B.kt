fun main(args: Array<String>) {
    val (n) = readLine()!!.split(' ').map(String::toInt)
    val a = readLine()!!.split(' ').map(String::toInt)
    var mx1 = 0
    var mx2 = 0
    var ans = 0
    for (i in 0..(n - 1)) {
        if (a[i] >= mx1) {
            mx2 = mx1
            mx1 = a[i]
        } else if(a[i] >= mx2) {
            mx2 = a[i]
        }
        if (mx2 > a[i]) ans++
    }
    println(ans)
}