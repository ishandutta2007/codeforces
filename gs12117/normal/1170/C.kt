import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	val tcn=readInt()
	for(tc in 1..tcn){
		val sa=readLn()
		val sb=readLn()
		val sal=sa.length
		val sbl=sb.length
		var j=0
		var ans="YES"
		for(i in 0..sbl-1){
			if(j>=sal)ans="NO"
			else if(sb[i]=='+'){
				if(sa[j]=='+')j++
				else if(j+1<sal&&sa[j+1]=='-')j+=2
				else ans="NO"
			}
			else{
				if(sa[j]=='-')j++
				else ans="NO"
			}
		}
		if(j!=sal)ans="NO"
		println(ans)
	}
}