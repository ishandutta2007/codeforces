import java.util.*
 
fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    
    for (i in 1..n) {
    	val nums = readLine()!!.split(" ").map { it.toInt() }
    	if (nums[0] == nums[1])
    		println("1 1 " + (nums[0] - 1))
    	else if (nums[0] < nums[1])
    		println("1 " + (nums[0] - 1) + " " + (nums[1] - nums[0] + 1))
    	else
    		println("1 " + (nums[1] - 1) + " " + (nums[0] - nums[1] + 1))
    }
}