fun main(){
    repeat(readLine()!!.toInt()){
        var (A, B) = readLine()!!.split(' ').map({it.toLong()})
        println(A * ((B + 1).toString().length - 1))
    }
}