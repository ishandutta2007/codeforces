fun main(){
    repeat(readLine()!!.toInt()){
        val n = readLine()!!.toInt()
        val s = readLine()!!.split(' ').map(String::toInt).sorted()
        println(Array(n - 1){s[it + 1] - s[it]}.min()!!)
    }
}