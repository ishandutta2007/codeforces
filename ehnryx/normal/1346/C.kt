import java.io.*;
import java.util.*;
import kotlin.math.*;

fun main() = output {
  val T = readInt();
  repeat(T) {
    val (n, k, x, y) = readLongs(4);
    val a = readLongs(n.toInt()).sortedDescending();

    var ansx = 0L;
    var ansy = y;
    var sum = a.sum();
    val threshold = n * k;
    for (v in a) {
      if (v > k) {
        ansx += x;
      }
      if (sum > threshold) {
        sum -= v;
        ansy += x;
      }
    }

    println(min(ansx, ansy));
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