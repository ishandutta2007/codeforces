import java.io.*;
import java.util.*;
import kotlin.math.*;

fun main() = output {
  val T = readInt();
  repeat(T) {
    val (n, m) = readInts(2);
    val edges = mutableListOf<Edge>();
    repeat(m) {
      val (a, b, c) = readInts(3);
      edges.add(Edge(a, b, c));
    }
    edges.sortDescending();

    val ans = Array<Int>(n + 1) { _ -> 0; }
    var ok = true;
    for ((a, b, c) in edges) {
      ans[a] = max(ans[a], c);
      ans[b] = max(ans[b], c);
      if (c != min(ans[a], ans[b])) {
        ok = false;
        break;
      }
    }

    if (ok) {
      println("YES");
      println(ans.slice(IntRange(1, n)).joinToString(" "));
    } else {
      println("NO");
    }
  }
}

class Edge: Comparable<Edge> {
  val a: Int;
  val b: Int;
  val c: Int;
  constructor(a: Int, b: Int, c: Int) {
    this.a = a;
    this.b = b;
    this.c = c;
  }
  override operator fun compareTo(other: Edge): Int {
    return this.c - other.c;
  }
  operator fun component1(): Int { return a; }
  operator fun component2(): Int { return b; }
  operator fun component3(): Int { return c; }
};

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