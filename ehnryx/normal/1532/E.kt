import java.io.*;
import java.util.*;

fun main() = output {
  val n = readInt();
  val a = readLongs(n);
  val cnt = mutableMapOf<Long, Int>();
  a.forEach {
    cnt.set(it, cnt.getOrDefault(it, 0) + 1);
  };
  val sum = a.sum();
  val ans = mutableListOf<Int>();
  a.forEachIndexed { i, value ->
    val rem = sum - value;
    if (rem % 2 != 0L) return@forEachIndexed;
    when (rem / 2) {
      value -> {
        if (cnt.getOrDefault(rem / 2, 0) >= 2) {
          ans.add(i + 1);
        }
      }
      else -> {
        if (cnt.getOrDefault(rem / 2, 0) >= 1) {
          ans.add(i + 1);
        }
      }
    }
  };
  println(ans.size);
  println(ans.joinToString(" "));
}

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