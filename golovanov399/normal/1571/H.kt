import kotlin.math.*

const val mod = 998_244_353

fun reduceInt(x: Int): Int {
    return x - (if (x >= mod) mod else 0)
}

fun reduce(x: Long): Int {
    return (x % mod).toInt()
}

fun intInv(x: Int): Int = if (x == 1) {
    1
} else {
    mod - reduce(intInv(mod % x) * (mod / x).toLong())
}

class Mint(private val x: Int) {
    operator fun plus(ot: Mint) = Mint(reduceInt(x + ot.x))
    operator fun plus(ot: Int) = Mint(reduceInt(x + ot))
    operator fun minus(ot: Mint) = Mint(reduceInt(x + mod - ot.x))
    operator fun times(ot: Mint) = Mint(reduce(1L * x * ot.x))
    override fun toString() = x.toString()
    fun equals(ot: Mint) = x == ot.x
    fun inv(): Mint {
        return Mint(intInv(x))
    }
    fun toInt() = x
}

data class Enemy(val x: Int, val y: Int, val p: Mint)

fun solve() {
    val (n, a, b) = readLine()!!.split(' ').map(String::toInt)
    var ans = Mint(1 - (a - 1) * (b - 1) - a * b)
    val inverseMillion = Mint(1_000_000).inv()
    val enemies = (0 until n).map {
        val line = readLine()!!.split(' ').map(String::toInt)
        Enemy(line[0], line[1], Mint(line[2]) * inverseMillion)
    }
    for (x in 1..a) {
        for (y in 1..b) {
            var probIsolated = Mint(1)
            if (x == a || y == b) {
                probIsolated = Mint(0)
            }
            enemies.forEach { (ex, ey, p) ->
                if (ex == x || ey == y) {
                    probIsolated = Mint(0)
                } else if (abs(ex - x) == abs(ey - y)) {
                    probIsolated *= Mint(1) - p
                }
            }
            val probForwDiag = Mint(1) - enemies.filter { x + y - 1 == it.x + it.y }.fold(Mint(1)) { p, e -> p * (Mint(1) - e.p) }
            val probBackDiag = Mint(1) - enemies.filter { x - y == it.x - it.y }.fold(Mint(1)) { p, e -> p * (Mint(1) - e.p) }

//            println("$x $y:")
            ans += probIsolated
//            println("- $probIsolated")
            ans += Mint(if (enemies.any { it.y == y }) 1 else 0)
//            println("- ${Mint(if (enemies.any { it.y == y }) 1 else 0)}")
            ans += Mint(if (enemies.any { it.x == x }) 1 else 0)
//            println("- ${Mint(if (enemies.any { it.x == x }) 1 else 0)}")
            ans += probForwDiag * Mint(2)
//            println("- ${probForwDiag}")
            ans += probBackDiag * Mint(2)
//            println("- ${probBackDiag}")
            ans += (Mint(1) - probForwDiag) * (Mint(1) - probBackDiag)
//            println("- ${Mint(1) - probBackDiag * probForwDiag}")
        }
    }
    println(ans)
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}