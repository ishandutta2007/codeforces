import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	val n=readInt()
	val p=readInts()
	var ans=0
	var pa=0
	var pb=0
	for(i in 0..n-1){
		if(p[i]>=pa){
			pb=pa
			pa=p[i]
		}
		else if(p[i]>=pb){
			pb=p[i]
		}
		else ans++
	}
	println(ans)

}