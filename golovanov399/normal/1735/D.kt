fun solve() {
    val (n, k) = readLine()!!.split(' ').map(String::toInt)
    val a = List(n) {
        readLine()!!.split(" ").map(String::toInt)
    }
    fun hash(a: List<Int>): Int = a.fold(0) { x, y -> 3 * x + y }
    fun other(a: List<Int>, b: List<Int>): List<Int> = a.zip(b).map { (x, y) -> (6 - x - y) % 3 }
    val m = mutableMapOf<Int, Int>()
    for (i in 0 until n) {
        for (j in 0 until i) {
            val x = hash(other(a[i], a[j]))
            m[x] = m.getOrDefault(x, 0) + 1
        }
    }
    println(a.sumOf {
        val x = hash(it)
        val c = m.getOrDefault(x, 0)
        1L * c * (c - 1) / 2
    })
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}