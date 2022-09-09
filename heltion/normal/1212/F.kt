
fun pow(a : Long, r : Int) : Long = if(r == 0) 1L else pow(a, r - 1) * a
var p = Array(16){i -> (pow(10L, i + 1) - 1) / 9}
fun solve(n : Long, i : Int) : Int{
    var res = (n / p[i] * (i + 1)).toInt()
    var m = n % p[i]
    if(m == 0L) return res
    return res + minOf(i + 1 + solve(p[i] - m, i - 1), solve(m, i - 1))
}
fun main() {
    print(solve(readLine()!!.toLong(), 15))
}