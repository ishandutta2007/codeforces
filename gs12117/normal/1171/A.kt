import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	val tc = readInt()
	for(i in 0..tc-1) {
		val n=readInt()
		println(n/2)
	}
	
}