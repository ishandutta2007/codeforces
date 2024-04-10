fun main(){
    var(n,k)=readLine()!!.split(' ').map{x->x.toInt()}
    while (k--!=0){
        if (n%10==0){
            n/=10
        }
        else{
            n--
        }
    }
    println(n)
}