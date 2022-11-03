
import java.lang.StringBuilder
import java.lang.System.`in`

fun main() {
    val br = `in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    for( case in 1..numCases){
        val (size, base) = br.readLine().split(' ').map(String::toLong)
        val nums = br.readLine().split(' ').map(String::toLong).toMutableList()
        var good = true
        var allZero = false
        var i = 0L
        while(good && !allZero){
            var assigned = false
            allZero = true
            for(id in nums.indices){
                val num = nums[id]
                if(num != 0L){
                    allZero = false
                    when(num%base){
                        0L -> good = good

                        1L -> {
                            if(assigned){
                                good = false
                            }
                            nums[id] -= 1L
                            assigned = true
                        }
                        else -> good = false
                    }
                    nums[id] /= base
                }
            }
        }

        if(good){
            sb.append("YES\n")
        } else {
            sb.append("NO\n")
        }
    }
    print(sb)
}