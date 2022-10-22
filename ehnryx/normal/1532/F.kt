import java.io.*;
import java.util.*;

fun main() = output {
  val n = readInt();
  val all = readStrings(2*(n-1));

  val candidates = mutableListOf<String>();
  for (s in all) {
    if (s.length == n-1) {
      candidates.add(s);
    }
  }
  var (prefix, suffix) = candidates;

  for (rep in 1..2) {
    val cnt = mutableMapOf<String, Int>();
    for (s in all) {
      cnt.set(s, cnt.getOrDefault(s, 0) + 1);
    }

    var ok = true;
    for (len in 1..n-1) {
      val subprefix = prefix.substring(0, len);
      if (cnt.getOrDefault(subprefix, 0) == 0) {
        ok = false;
        break;
      }
      cnt.set(subprefix, cnt.get(subprefix)!! - 1);
      val subsuffix = suffix.substring(n-len - 1);
      if (cnt.getOrDefault(subsuffix, 0) == 0) {
        ok = false;
        break;
      }
      cnt.set(subsuffix, cnt.get(subsuffix)!! - 1);
    }

    if (ok) {
      val prefixes = mutableSetOf<String>();
      for (len in 1..n-1) {
        prefixes.add(prefix.substring(0, len));
      }
      val ans = StringBuilder();
      all.forEachIndexed { _, s ->
        if (prefixes.remove(s)) {
          ans.append('P');
        } else {
          ans.append('S');
        }
      }
      println(ans);
      break;
    }

    prefix = suffix.also { suffix = prefix };
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