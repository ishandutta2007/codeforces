import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	val (a,b,c)=readInts()
	var p=a
	if(p>b-1)p=b-1
	if(p>c-2)p=c-2
	println(3*p+3)

}