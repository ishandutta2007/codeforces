fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    repeat(numCases){
        val (n, x) = br.readLine().split(' ').map(String::toInt)
        val nums = br.readLine().split(' ').map(String::toInt)
        var numOdd = 0
        var numEven = 0
        for(num in nums){
            if(num and 1 == 0){
                numEven++
            } else {
                numOdd++
            }
        }
        val valid = if(numOdd < 1){
            false
        } else if(x == n){
            numOdd and 1 == 1
        } else if(numEven > 0){
            true
        } else{
            x and 1 == 1
        }
        if(valid){
            sb.append("Yes\n")
        } else {
            sb.append("No\n")
        }
    }
    print(sb)
}