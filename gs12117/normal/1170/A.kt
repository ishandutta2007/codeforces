import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	val tcn=readInt()
	for(tc in 1..tcn){
		val (a,b)=readInts()
		var p=a
		if(p>b)p=b
		p--
		println(p.toString()+" "+(a-p)+" "+(b-p))
	}

}