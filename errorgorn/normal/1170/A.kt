fun main(){
    var TC=readLine()!!.toInt()
    repeat(TC){
        var (a,b)=readLine()!!.split(' ').map { it->it.toInt() }
        if (a>b){
            var c=a
            a=b
            b=c
        }
        print("${b-a+1} ${a-1} 1\n")
    }
}