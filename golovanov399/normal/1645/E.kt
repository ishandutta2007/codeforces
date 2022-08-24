import kotlin.math.*

fun solve() {
    val (n, k) = readLine()!!.split(' ').map(String::toInt)
    if (k < n.countOneBits() || k > n) {
        println("NO")
        return
    }
    val ans = (0..30).filter { n and (1 shl it) > 0 }.map { 1 shl it }.toMutableList()
    var i = 0
    var rem = k - ans.size
    var cntOnes = 0
    while (rem > 0) {
        if (ans[i] > 1) {
            ans.add(ans[i] / 2)
            ans.add(ans[i] / 2)
            rem -= 1
        } else {
            cntOnes += 1
        }
        i += 1
    }
    println("YES")
    print(List(cntOnes) { "1 " }.joinToString(""))
    println(ans.drop(i).joinToString(" "))
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}