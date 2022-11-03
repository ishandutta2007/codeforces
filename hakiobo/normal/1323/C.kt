
import java.lang.System.`in`

fun main() {
    val br = `in`.bufferedReader()
    val length = br.readLine().toInt()
    val seq = br.readLine()
    var net = 0
    var reorderTime = 0
    seq.forEach {
        if(it == '('){
            net += 1
            if(net == 0){
                reorderTime++
            }
        } else {
            net -= 1
        }
        if(net < 0){
            reorderTime++
        }
    }
    if(net == 0) {
        print(reorderTime)
    } else {
        print(-1)
    }
}