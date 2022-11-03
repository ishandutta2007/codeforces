fun main() {
    val num = System.`in`.bufferedReader().readLine().toInt()
    var result = 0
    if(num and 1 == 1){
        result += 16
    }
    if(num and 2 == 2){
        result += 2
    }
    if(num and 4 == 4){
        result += 8
    }
    if(num and 8 == 8){
        result += 4
    }
    if(num and 16 == 16){
        result += 1
    }
    if(num and 32 == 32){
        result += 32
    }
    print(result)
}