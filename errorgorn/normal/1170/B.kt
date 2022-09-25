fun main(){
    var size=readLine()!!.toInt()
    val arr=readLine()!!.split(' ').map{x->x.toInt()}
    arr.toIntArray()
    var b1=0
    var b2=0
    var ans=0
    for (x in 0..size-1){
        if (arr[x]>=b2){
            b2=arr[x]
            if (b2>b1) b1=b2.also { b2=b1 }
        }
        else{
            ans++
        }
    }
    println(ans)
}