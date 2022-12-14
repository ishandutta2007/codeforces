fun main() {
    var n = readLine()!!.toInt()
    var ans = 9
    while (n >= 10) {
        n += 1
        while (n % 10 == 0) n /= 10
        ans++
    }
    println(ans)
}