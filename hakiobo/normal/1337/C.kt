import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val (n, k) = br.readLine().split(' ').map(String::toInt)
    val connections = Array(n) {
        emptyList<Int>().toMutableList()
    }
    repeat(n - 1) {
        val (a, b) = br.readLine().split(' ').map { it.toInt() - 1 }
        connections[a].add(b)
        connections[b].add(a)
    }
    val depths = IntArray(n)
    val nodesBelow = IntArray(n)
    val parent = IntArray(n)
    val itrStack: Deque<Iterator<Int>> = ArrayDeque()
    val nodeStack: Deque<Int> = ArrayDeque()
    itrStack.push(connections[0].iterator())
    nodeStack.push(0)
    var depth = 0
    while (itrStack.isNotEmpty()) {
        val curItr = itrStack.peek()
        val curNode = nodeStack.peek()
        val next = if (curItr.hasNext()) {
            val poss = curItr.next()
            if (poss == parent[curNode]) {
                if (curItr.hasNext()) {
                    curItr.next()
                } else {
                    -1
                }
            } else {
                poss
            }
        } else {
            -1
        }

        if (next == -1) {
            depth--
            if (curNode != 0) {
                nodesBelow[parent[curNode]] += 1 + nodesBelow[curNode]
            }
            itrStack.pop()
            nodeStack.pop()
        } else {
            depths[next] = ++depth
            parent[next] = curNode
            itrStack.push(connections[next].iterator())
            nodeStack.push(next)
        }
    }
    val scores = IntArray(n) {
        depths[it] - nodesBelow[it]
    }
    scores.sortDescending()
    var score = 0L
    for (x in 0 until k) {
        score += scores[x]
    }
    print(score)
}