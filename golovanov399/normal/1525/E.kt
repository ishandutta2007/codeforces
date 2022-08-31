import java.lang.NumberFormatException
import kotlin.math.*

const val mod = 998_244_353

class Mint(private val x: Int): Number() {
    override fun toInt() = x

    override fun toByte() = x.toByte()

    override fun toChar() = x.toChar()

    override fun toDouble() = x.toDouble()

    override fun toFloat() = x.toFloat()

    override fun toLong() = x.toLong()

    override fun toShort() = x.toShort()

    operator fun plus(other: Number): Mint {
        val y = x + other.toInt()
        return if (y >= mod) Mint(y - mod) else Mint(y)
    }

    operator fun minus(other: Number): Mint {
        val y = x - other.toInt()
        return if (y < 0) Mint(y + mod) else Mint(y)
    }

    operator fun times(other: Number): Mint {
        return Mint((x * other.toLong() % mod).toInt())
    }

    override fun toString(): String = x.toString()
}

fun solve() {
    val (n, m) = readLine()!!.split(' ').map(String::toInt)
    val a = List(n) { readLine()!!.split(' ').map(String::toInt) }

    fun prob(l: List<Int>) = l.withIndex().fold(Mint(1)) { cur, iv -> cur * (iv.value - iv.index - 1) }
    val invFact = (1..n).map { k -> (1L..(k * mod.toLong() + 1) step mod.toLong()).first { it % k == 0L } / k }
            .map { Mint((it % mod).toInt()) }.fold(Mint(1), Mint::times)

    println(Mint(m) - (0 until m).map { j -> prob(a.map { it[j] }.sorted()) }.fold(Mint(0), Mint::plus) * invFact)
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}