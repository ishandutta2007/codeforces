fun main() {
    val br = System.`in`.bufferedReader()
    val numCases = br.readLine().toInt()
    val sb = StringBuilder()
    for (case in 1..numCases) {
        val (l, r, d, u) = br.readLine().split(' ').map(String::toInt)
        val input2 = br.readLine().split(' ').map(String::toInt)
        val (xStart, yStart) = input2.take(2)
        val (lx, dy, rx, uy) = input2.takeLast(4)
        if (lx == rx) {
            if (l != 0 || r != 0) {
                sb.append("No\n")
                continue
            }
        }
        if (dy == uy) {
            if (u != 0 || d != 0) {
                sb.append("No\n")
                continue
            }
        }
        val netX = r - l
        val netY = u - d
        if(netX + xStart in lx..rx && netY + yStart in dy..uy){
            sb.append("Yes\n")
        } else {
            sb.append("No\n")
        }
    }
    print(sb)
}