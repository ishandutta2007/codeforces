fun main(){
    readLine()
    val x = mutableListOf<Int>()
    val set = mutableSetOf<Int>()
    for(a in readLine()!!.split(' ').map{it.toInt()}.reversed()){
        if(!set.contains(a)) x.add(a)
        set.add(a)
    }
    println(x.size)
    for(a in x.reversed()) println(a)
}