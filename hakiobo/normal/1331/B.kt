fun main() {
    val num = System.`in`.bufferedReader().readLine().toInt()
    for(i in 2 until num){
        var temp = num
        while(temp%i == 0){
            print(i)
            temp /= i
        }
    }
}