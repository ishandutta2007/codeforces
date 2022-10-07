import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	val (n,m,k)=readInts()
	val a=readInts().sorted()
	var ans=99999999999999999L
	var kleft=k+0L
	var pvt=0L
	var j=0
	val sumd=LongArray(n+1)
	for(i in 0..n-1){
		sumd[i+1]=sumd[i]+a[i]
	}
	for(i in 0..n-m){
		if(pvt<a[i]+0L)pvt=a[i]+0L
		if(j<i+1)j=i+1
		while(j<=m/2+i){
			val kld=kleft/(j-i)
			if(kld<a[j]-pvt){
				pvt+=kld
				kleft-=kld*(j-i)*1L
				break
			}
			kleft-=(a[j]-pvt)*(j-i)*1L
			pvt=a[j]+0L
			j++
		}
		val tans=sumd[i+m]-sumd[i]-1L*pvt*m+2L*(k-kleft)
		if(tans<ans)ans=tans
		kleft+=pvt-a[i]
	}
	println(ans)
}