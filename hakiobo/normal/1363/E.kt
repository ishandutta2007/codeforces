import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readLine().toInt()
    var oddNums = 0
    var oddGoals = 0
    val costs = LongArray(n)
    val zeroToOne = IntArray(n)
    val oneToZero = IntArray(n)
    repeat(n) { idx ->
        val (cost, init, goal) = br.readLine().split(' ').map(String::toInt)
        if (init == 1) oddNums++
        if (goal == 1) oddGoals++
        if (init == 0 && goal == 1) zeroToOne[idx] = 1
        if (init == 1 && goal == 0) oneToZero[idx] = 1
        costs[idx] = cost.toLong()
    }
    if (oddGoals == oddNums) {
        val connections = Array(n) { mutableListOf<Int>() }
        repeat(n - 1) {
            val (a, b) = br.readLine().split(' ').map { it.toInt() - 1 }
            connections[a].add(b)
            connections[b].add(a)
        }

        var totCost = 0L

        IteratorDFS(connections){ dsc, curr, next ->
            if(dsc){
                costs[next] = costs[next].coerceAtMost(costs[curr])
            } else {
                val toSwap = zeroToOne[curr].coerceAtMost(oneToZero[curr])
                totCost += costs[curr] * toSwap shl 1
                if(next != curr){
                    zeroToOne[next] += zeroToOne[curr] - toSwap
                    oneToZero[next] += oneToZero[curr] - toSwap
                }
            }
        }
        print(totCost)
    } else {
        print(-1)
    }
}

private class IteratorDFS(c: List<Iterable<Int>>, val p: IntArray = IntArray(c.size), root: Int = 0, b: (Boolean, Int, Int) -> Unit) {
    constructor(c: Array<out Iterable<Int>>, p: IntArray = IntArray(c.size), root: Int = 0, b: (Boolean, Int, Int) -> Unit): this(c.toList(), p, root, b)
    init {
        val i = ArrayDeque<Iterator<Int>>()
        var cn = root
        p[root] = root
        i.push(c[root].iterator())
        while (i.isNotEmpty()) {
            if (i.peek().hasNext()) {
                val nx = i.peek().next()
                if (nx != p[cn]) {
                    p[nx] = cn
                    b(true, cn, nx)
                    i.push(c[nx].iterator())
                    cn = nx
                }
            } else {
                val pn = p[cn]
                b(false, cn, pn)
                cn = pn
                i.pop()
            }
        }
    }
}