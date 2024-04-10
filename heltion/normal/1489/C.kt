fun main() {
    val n = readLine()!!.toInt()
    val s = readLine()!!
    var ans = 0
    var sum = 0
    for(c in s)
        if(c != 'x'){
            ans += maxOf(sum - 2, 0)
            sum = 0
        }else sum += 1
    ans += maxOf(sum - 2, 0)
    println(ans)
}