import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	val (n,m)=readInts()
	val a=readInts()
	val q=readInt()
	var b=IntArray(n+1)
	for(i in 0..n-1){
		b[i+1]=b[i]+a[i]
	}
	val set=TreeSet<Int>()
	for(i in b)set.add(i)
	var out=ArrayList<String>()
	for(i in 0..q-1){
		val w=ArrayList<Int>(readInts())
		val c=w[0]
		w[0]=0
		w.add(m+1)
		var p=0
		for(j in 0..c){
			val x=w[j+1]-w[j]+p
			p=set.lower(x)
		}
		var outs="YES"
		if(p<set.last())outs="NO"
		out.add(outs)
	}
	println(out.joinToString("\n"))
}