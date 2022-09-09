fun main(){
    repeat(readLine()!!.toInt()){
        val n = readLine()!!.toInt()
        if(n % 2 == 1) print(7)
        repeat(if(n % 2 == 1) n / 2 - 1 else n / 2) {
            print(1)
        }
        println()
    }
}