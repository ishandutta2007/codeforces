import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	val m=readInt()
	val s=readInts()
	var n=0
	for(i in 0..s.size-1){
		if(s[i]==-1)n++
	}
	val p=Array<MutableList<Int>>(n, {ArrayList<Int>()})
	val ended=BooleanArray(n, {false})
	val set=TreeSet<Int>()
	for(i in 0..n-1){
		set.add(i)
	}
	var x=0
	while(true){
		val rset=TreeSet<Int>()
		for(i in set){
			if(s[x]==-1)rset.add(i)
			else p[i].add(s[x])
			x++
		}
		for(i in rset){
			set.remove(i)
		}
		if(set.isEmpty())break
	}
	println(n)
	var out=ArrayList<String>()
	for(i in 0..n-1){
		var outp=ArrayList<Int>()
		outp.add(p[i].size)
		for(j in p[i]){
			outp.add(j)
		}
		out.add(outp.joinToString(" "))
	}
	println(out.joinToString("\n"))
}