
import java.lang.System.`in`

fun main() {
    val (xorVal, sum) = `in`.bufferedReader().readLine().split(' ').map(String::toLong)
    if(xorVal > sum || ((xorVal and 1L) xor (sum and 1L)) == 1L){
        print(-1)
    } else if(xorVal == sum){
        if(xorVal == 0L){
            print(0)
        } else {
            println(1)
            print(xorVal)
        }
    } else {
        val value = (sum - xorVal) shr 1
        if(value and xorVal == 0L){
            println(2)
            print(xorVal or value)
            print(' ')
            print(value)
        } else {
            println(3)
            print(xorVal)
            print(' ')
            print(value)
            print(' ')
            print(value)
        }
    }
}