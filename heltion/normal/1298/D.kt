fun main(){
    val (_ , w) = readLine()!!.split(' ').map{it.toInt()}
    var L = 0
    var R = w
    for(a in readLine()!!.split(' ').map{it.toInt()}.reversed()){
        L = maxOf(0, L - a)
        R = minOf(w, R - a)
        if(L > R) {
            print(0)
            return
        }
    }
    print(R - L + 1)
}