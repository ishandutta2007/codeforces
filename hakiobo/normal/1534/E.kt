fun main() {
    val br = System.`in`.bufferedReader()
    val (n, k) = br.readLine().split(" ").map { it.toInt() }
    val processed = BooleanArray(n + 1)
    val prev = IntArray(n + 1) { -1 }
    val queue = ArrayDeque<Int>()
    queue.addLast(0)
    processed[0] = true
    while (queue.isNotEmpty()) {
        val numKnown = queue.removeFirst()
        val numUnknown = n - numKnown
        for (x in 0..k) {
            if (x > numKnown || (k - x) > numUnknown) continue
            val newState = numKnown + k - 2 * x
            if (!processed[newState]) {
                processed[newState] = true
                queue.addLast(newState)
                prev[newState] = numKnown
            }
        }
    }
    if (processed.last()) {
        var ans = 0
        val unknownIdx = MutableList(n) { x -> x + 1 }
        val knownIdx = mutableListOf<Int>()
        while (unknownIdx.isNotEmpty()) {
            val prevUnknown = prev[unknownIdx.size]
            val (unknownToQuery, knownToQuery) = if (prevUnknown - unknownIdx.size > 0) {
                val shared = (k - prevUnknown + unknownIdx.size) shr 1
                shared to shared + prevUnknown - unknownIdx.size
            } else {
                val shared = (k + prevUnknown - unknownIdx.size) shr 1
                shared + unknownIdx.size - prevUnknown to shared
            }
            val toQueryA = mutableListOf<Int>()
            val toQueryB = mutableListOf<Int>()
            repeat(unknownToQuery) {
                toQueryA += unknownIdx.removeLast()
            }
            repeat(knownToQuery) {
                toQueryB += knownIdx.removeLast()
            }
            println("? ${toQueryA.joinToString(" ")} ${toQueryB.joinToString(" ")}")
            ans = ans xor br.readLine().toInt()
            unknownIdx.addAll(toQueryB)
            knownIdx.addAll(toQueryA)
        }
        println("! $ans")
    } else {
        println(-1)
    }

}