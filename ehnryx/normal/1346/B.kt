import java.io.*;
import java.util.*;

fun main() = output {
  val T = readInt();
  repeat(T) {
    val (_, k1, k2) = readInts(3);
    val blocks = read().split("0").map { it.length };
    var ans = 0;
    for (s in blocks) {
      ans += (s + 1) / 2 * k1 + s / 2 * listOf(k1, k2 - k1).minOrNull()!!;
    }
    println(ans);
  }
}

//  Fast I/O  ///////
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
fun readDoubles(n: Int) = List(n) { read().toDouble() }
fun readLongs(n: Int) = List(n) { read().toLong() }

@JvmField val _writer = PrintWriter(OUTPUT, false)
inline fun output(block: PrintWriter.() -> Unit) { _writer.apply(block).flush() }