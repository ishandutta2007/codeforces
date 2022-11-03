fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    repeat(numCases){
        val n = br.readLine().toInt()
        val nums = br.readLine().split(' ').map(String::toInt).sorted()
        var idx = (n-1)/2
        var mag = 1
        var dir = 1
        while(idx in 0 until n){
            sb.append(nums[idx])
            sb.append(' ')
            idx += mag * dir
            mag += 1
            dir *= -1
        }
        sb.append('\n')
    }
    print(sb)
}