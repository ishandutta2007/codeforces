fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val (n, m, k) = br.readLine().split(' ').map(String::toInt)
    val swaps = Array(m) {
        val (x, y) = br.readLine().split(' ').map(String::toInt)
        Pair(x - 1, y - 1)
    }
    val minSwaps = IntArray(n) { -1 }
    minSwaps[k - 1] = 0
    for (swap in swaps) {
        val a = swap.first
        val b = swap.second
        val fakeA = minSwaps[a]
        val fakeB = minSwaps[b]
        if(fakeA != -1 && fakeB != -1){
            minSwaps[a] = fakeB.coerceAtMost(fakeA + 1)
            minSwaps[b] = fakeA.coerceAtMost(fakeB + 1)
        } else if (fakeA != -1){
            minSwaps[a]++
            minSwaps[b] = fakeA
        } else if(fakeB != -1){
            minSwaps[b]++
            minSwaps[a] = fakeB
        }
    }
    for (i in minSwaps) {
        sb.append(i).append(' ')
    }
    print(sb)
}