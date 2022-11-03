import java.io.BufferedReader
import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numNodes = br.readInt()
    val numQueries = br.readInt()
//    val (numNodes, numQueries) = br.readLine().split(' ').map(String::toInt)
    val connections = Array(numNodes) { emptyList<Int>().toMutableList() }
    val parents = IntArray(numNodes) { -1 }
    for (i in 0 until numNodes - 1) {
        val a = br.readInt() - 1
        val b = br.readInt() - 1
//        val (a, b) = br.readLine().split(' ').map { it.toInt() - 1 }
        connections[a].add(b)
        connections[b].add(a)
    }
    var id = 0
    val inTimes = IntArray(numNodes)
    val outTimes = IntArray(numNodes)
    val itrStk: Deque<Iterator<Int>> = ArrayDeque()
    val nodeStk: Deque<Int> = ArrayDeque()
    nodeStk.push(0)
    itrStk.push(connections[0].iterator())
    parents[0] = 0
    inTimes[0] = id++
    while (itrStk.isNotEmpty()) {
        val curItr = itrStk.peek()
        val curNode = nodeStk.peek()
        var next = -1
        if (curItr.hasNext()) {
            next = curItr.next()
            if (next == parents[curNode]) {
                next = if (curItr.hasNext()) curItr.next() else -1
            }
        }
        if (next == -1) {
            itrStk.pop()
            outTimes[nodeStk.pop()] = id++
        } else {
            inTimes[next] = id++
            parents[next] = curNode
            nodeStk.push(next)
            itrStk.push(connections[next].iterator())
        }
    }

    repeat(numQueries) {
        val numNums = br.readInt()
        val nums = IntArray(numNums) { parents[br.readInt() - 1] }
//        val nums = br.readLine().split(' ').drop(1).map { parents[it.toInt() - 1] }
        var inTime = inTimes[nums.first()]
        var outTime = outTimes[nums.first()]
        var good = true
        nums.forEach {
            val curIn = inTimes[it]
            val curOut = outTimes[it]
            if (curIn in inTime..outTime) {
                inTime = curIn
                outTime = curOut
            } else if (inTime !in curIn..curOut) {
                good = false
            }
        }
        sb.append(if (good) "YES\n" else "NO\n")
    }
    print(sb)
}

private const val ZERO_INT = '0'.toInt()
private const val SPACE_INT = ' '.toInt()
private fun BufferedReader.readInt(): Int {
    var ret = read()
    while (ret <= SPACE_INT) { // really simple whitespace check
        ret = read()
    }
    var isNeg = false
    if (ret == '-'.toInt()) {
        isNeg = true
        ret = read()
    }
    ret -= ZERO_INT
    var read = read()
    while (read >= ZERO_INT) {
        ret *= 10
        ret += read - ZERO_INT
        read = read()
    }
    return if (isNeg) -ret else ret
}