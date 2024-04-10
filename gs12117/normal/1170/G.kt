import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	val (n,m)=readInts()
	val el=Array<TreeMap<Int,Int>>(n,{TreeMap<Int,Int>()})
	for(i in 0..m-1){
		val (x,y)=readInts()
		el[x-1].set(y-1,(el[x-1].get(y-1)?:0)+1)
		el[y-1].set(x-1,(el[y-1].get(x-1)?:0)+1)
	}
	val ans=ArrayList<String>()
	for(i in 0..n-1){
		while(el[i].size>0){
			val anst=ArrayList<Int>()
			val anss=TreeSet<Int>()
			var x=i
			while(true){
				if(el[x].size==0){
					println("NO")
					return
				}
				val y=el[x].lastKey()
				el[x].set(y,el[x].get(y)!!-1)
				el[y].set(x,el[y].get(x)!!-1)
				if(el[x].get(y)==0)el[x].remove(y)
				if(el[y].get(x)==0)el[y].remove(x)
				anst.add(x)
				anss.add(x)
				if(anss.contains(y)){
					val ansr=ArrayList<Int>()
					ansr.add(y+1)
					while(anst[anst.size-1]!=y){
						val z=anst[anst.size-1]
						anst.removeAt(anst.size-1)
						anss.remove(z)
						ansr.add(z+1)
					}
					ansr.add(y+1)
					ans.add(ansr.size.toString()+" "+ansr.joinToString(" "))
					if(el[i].size==0)break
					anst.removeAt(anst.size-1)
					anss.remove(y)
				}
				x=y
			}
		}
	}
	println("YES")
	println(ans.size)
	println(ans.joinToString("\n"))
}