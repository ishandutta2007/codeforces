@file:Suppress("NOTHING_TO_INLINE", "EXPERIMENTAL_FEATURE_WARNING", "OVERRIDE_BY_INLINE")

import java.io.PrintWriter
import java.util.StringTokenizer
import kotlin.random.*
import kotlin.collections.sort as _sort
import kotlin.collections.sortDescending as _sortDescending

fun main() { _writer.solve(); _writer.flush() }
fun PrintWriter.solve() {
    val MAX = 2.2e5.toInt()
    val index = IntArray(MAX) { MAX }
    var left = 0
    var right = 0
    var was = false
    repeat(readInt()) {
        val (tp, id) = readLine()!!.split(" ").let {
            it[0][0] to it[1].toInt()
        }
        when (tp) {
            '?' -> {
                println(index[id].let { minOf(it - left - 1, right - it - 1)})
            }
            'L' -> {
                index[id] = left--
                if (!was) right++
                was = true
            }
            else -> {
                index[id] = right++
                if (!was) left--
                was = true
            }
        }
    }
}

/** IO code start */
//@JvmField val INPUT = File("input.txt").inputStream()
//@JvmField val OUTPUT = File("output.txt").outputStream()
@JvmField val INPUT = System.`in`
@JvmField val OUTPUT = System.out

@JvmField val _reader = INPUT.bufferedReader()
fun readLine(): String? = _reader.readLine()
fun readLn() = _reader.readLine()!!
@JvmField var _tokenizer: StringTokenizer = StringTokenizer("")
fun read(): String {
    while (_tokenizer.hasMoreTokens().not()) _tokenizer = StringTokenizer(_reader.readLine() ?: return "", " ")
    return _tokenizer.nextToken()
}
fun readInt() = read().toInt()
fun readDouble() = read().toDouble()
fun readLong() = read().toLong()
fun readStrings(n: Int) = List(n) { read() }
fun readLines(n: Int) = List(n) { readLn() }
fun readInts(n: Int) = List(n) { read().toInt() }
fun readIntArray(n: Int) = IntArray(n) { read().toInt() }
fun readDoubles(n: Int) = List(n) { read().toDouble() }
fun readDoubleArray(n: Int) = DoubleArray(n) { read().toDouble() }
fun readLongs(n: Int) = List(n) { read().toLong() }
fun readLongArray(n: Int) = LongArray(n) { read().toLong() }

@JvmField val _writer = PrintWriter(OUTPUT, false)

/** shuffles and sort overrides to avoid quicksort attacks */
private inline fun <T> _shuffle(rnd: Random, get: (Int) -> T, set: (Int, T) -> Unit, size: Int) {
    // Fisher-Yates shuffle algorithm
    for (i in size - 1 downTo 1) {
        val j = rnd.nextInt(i + 1)
        val temp = get(i)
        set(i, get(j))
        set(j, temp)
    }
}

@JvmField var _random: Random? = null
val random get() = _random ?: Random(0x594E215C123 * System.nanoTime()).also { _random = it }

fun IntArray.shuffle(rnd: Random = random) = _shuffle(rnd, ::get, ::set, size)
fun IntArray.sort() { shuffle(); _sort() }
fun IntArray.sortDescending() { shuffle(); _sortDescending() }

fun LongArray.shuffle(rnd: Random = random) = _shuffle(rnd, ::get, ::set, size)
fun LongArray.sort() { shuffle(); _sort() }
fun LongArray.sortDescending() { shuffle(); _sortDescending() }

fun DoubleArray.shuffle(rnd: Random = random) = _shuffle(rnd, ::get, ::set, size)
fun DoubleArray.sort() { shuffle(); _sort() }
fun DoubleArray.sortDescending() { shuffle(); _sortDescending() }

fun CharArray.shuffle(rnd: Random = random) = _shuffle(rnd, ::get, ::set, size)
inline fun CharArray.sort() { _sort() }
inline fun CharArray.sortDescending() { _sortDescending() }

inline fun <T: Comparable<T>> Array<out T>.sort() = _sort()
inline fun <T: Comparable<T>> Array<out T>.sortDescending() = _sortDescending()
inline fun <T: Comparable<T>> MutableList<out T>.sort() = _sort()
inline fun <T: Comparable<T>> MutableList<out T>.sortDescending() = _sortDescending()