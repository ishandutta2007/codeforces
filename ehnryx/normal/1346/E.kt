import java.io.*;
import java.util.*;
import kotlin.math.*;

fun main() = output {
  val inf = Int.MAX_VALUE / 2;
  val (n, m, k) = readInts(3);
  val ans = Array<Int>(n + 1) { _ -> inf; }
  ans[k] = 0;
  repeat(m) {
    val (a, b) = readInts(2);
    ans[a] = min(ans[a] + 1, ans[b]).also { ans[b] = min(ans[a], ans[b] + 1); }
  }
  println(
    ans.map {
      if (it >= inf) return@map -1;
      else return@map it;
    }.slice(IntRange(1, n)).joinToString(" "));
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