fun main(){
    var n=readLine()!!.toInt()
    var str=readLine()!!
    val total=IntArray(700)
    for (x in 1..n-1){
        total[hash(str[x-1],str[x])]++
    }
    var most=0
    for (x in 0..699){
        if (total[x]>total[most]) most=x
    }
    print("${((most/26)+'A'.toInt()).toChar() }${((most%26)+'A'.toInt()).toChar()}\n")
}
fun hash(i:Char, j:Char):Int{
    return (i-'A')*26 + (j-'A')
}