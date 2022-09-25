fun main(){
    var(n,k)=readLine()!!.split(' ').map{x->x.toInt()}
    val arr=readLine()!!.split(' ').map{x->x.toInt()}.sorted()
    if (k==n){
        print("1000000000\n")
    }
    else if (k==0){
        if (arr[0]==1) print("-1\n")
        else print("1\n")
    }
    else{
        if (arr[k]==arr[k-1]) print("-1\n")
        else print("${arr[k-1]}\n")
    }
}