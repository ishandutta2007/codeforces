import java.util.*


fun main() {
    val br = System.`in`.bufferedReader()
    val numNodes = br.readLine().toInt()
    val connections = Array(numNodes) { emptyList<Int>().toMutableList() }
    val numLeavesConnected = IntArray(numNodes)
    repeat(numNodes - 1) {
        val (a, b) = br.readLine().split(' ').map { it.toInt() - 1 }
        connections[a].add(b)
        connections[b].add(a)
    }
    var numSharedLeaves = 0
    var lastLeaf = 0
    for (x in 0 until numNodes) {
        if (connections[x].size == 1) {
            lastLeaf = x
            val par = connections[x].first()
            if (numLeavesConnected[par] != 0) {
                numSharedLeaves++
            }
            numLeavesConnected[par]++
        }
    }

    val iterStack: Deque<Iterator<Int>> = ArrayDeque()
    val par = IntArray(numNodes)
    val nodeStack: Deque<Int> = ArrayDeque()
    var depth = 0
    par[lastLeaf] = lastLeaf
    iterStack.push(connections[lastLeaf].iterator())
    nodeStack.push(lastLeaf)

    var onlyOneLabel = true

    while (iterStack.isNotEmpty()) {
        val curItr = iterStack.peek()
        val curNode = nodeStack.peek()
        if ((depth and 1) == 0 && numLeavesConnected[curNode] != 0) onlyOneLabel = false
        val next = if (curItr.hasNext()) {
            val posNext = curItr.next()
            if (posNext != par[curNode]) {
                posNext
            } else {
                if (curItr.hasNext()) {
                    curItr.next()
                } else {
                    -1
                }
            }
        } else {
            -1
        }
        if (next == -1) {
            iterStack.pop()
            nodeStack.pop()
            depth--
        } else {
            iterStack.push(connections[next].iterator())
            nodeStack.push(next)
            par[next] = curNode
            depth++
        }
    }
    val minNums = if (onlyOneLabel) 1 else 3
    print("%d %d".format(minNums, numNodes - numSharedLeaves - 1))
}