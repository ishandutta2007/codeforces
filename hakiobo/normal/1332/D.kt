fun main() {
    val k = System.`in`.bufferedReader().readLine().toInt()
    val large = 1 shl 17
    println("3 3")
    println(String.format("%d %d %d", large + k, large, 0))
    println(String.format("%d %d %d", k, large + k, k))
    println(String.format("%d %d %d", 0, k, k))
}