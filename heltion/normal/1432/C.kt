fun main(){
    repeat(readLine()!!.toInt()){
        val n = readLine()!!.toInt()
        println((readLine()!!.split(' ').map(String::toInt).sum() + n - 1) / n)
    }
}