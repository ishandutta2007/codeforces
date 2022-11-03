import java.io.BufferedReader
import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val m = br.readInt()
    val k = br.readInt()
    val cons = Array(n) { mutableListOf<Int>() }
    val backEdges = Array(n) { mutableListOf<Int>() }
    val depths = IntArray(n)
    repeat(m) {
        val a = br.readInt() - 1
        val b = br.readInt() - 1
        cons[a].add(b)
        cons[b].add(a)
    }

    val oddDepth = mutableListOf<Int>()
    val evenDepth = mutableListOf(1)
    val tree = m == n - 1
    val stack = ArrayDeque<Iterator<Int>>()
    val par = IntArray(n)
    val visited = BooleanArray(n)
    var cur = 0
    var depth = 0
    depths[0] = 0
    par[0] = 0
    visited[0] = true
    stack.push(cons[0].iterator())
    while (stack.isNotEmpty()) {
        if (stack.peek().hasNext()) {
            val next = stack.peek().next()
            if (next != par[cur]) {
                if (visited[next]) {
                    if(depths[cur] >= depths[next]){
                        backEdges[cur].add(next)
                    }
                } else {
                    depth++
                    if (tree) {
                        if (depth and 1 == 0) {
                            evenDepth += next + 1
                        } else {
                            oddDepth += next + 1
                        }
                    } else {
                        depths[next] = depth
                        visited[next] = true
                    }
                    par[next] = cur
                    stack.push(cons[next].iterator())
                    cur = next
                }
            }
        } else {
            depth--
            val pn = par[cur]
            cur = pn
            stack.pop()
        }
    }
    if (tree) {
        println(1)
        if (evenDepth.size > oddDepth.size) {
            print(evenDepth.take((k + 1) shr 1).joinToString(" "))
        } else {
            print(oddDepth.take((k + 1) shr 1).joinToString(" "))
        }
    } else {
        var start = -1
        for(x in 0 until n){
            if(backEdges[x].size > 0){
                if(start == -1){
                    start = x
                } else if(depths[x] < depths[start]){
                    start = x
                }
            }
        }
        var end = backEdges[start].first()
        for(upper in backEdges[start]){
            if(depths[upper] > depths[end]){
                end = upper
            }
        }
        val path = mutableListOf(start + 1)
        var node = start
        while (node != end) {
            node = par[node]
            path += node + 1
        }
        if (path.size <= k) {
            println(2)
            println(path.size)
            print(path.joinToString(" "))
        } else {
            println(1)
            print(path.filterIndexed { index, _ -> index and 1 == 0 }.take((k + 1) shr 1).joinToString(" "))
        }
    }
}


private const val SPACE_INT = ' '.toInt()
private const val ZERO_INT = '0'.toInt()
private const val NL_INT = '\n'.toInt()

@Suppress("DuplicatedCode")
private fun BufferedReader.readInt(): Int {
    var ret = read()
    while (ret <= SPACE_INT) {
        ret = read()
    }
    val neg = ret == '-'.toInt()
    if (neg) {
        ret = read()
    }
    ret -= ZERO_INT
    var read = read()
    while (read >= ZERO_INT) {
        ret *= 10
        ret += read - ZERO_INT
        read = read()
    }

    while (read <= SPACE_INT && read != -1 && read != NL_INT) {
        mark(1)
        read = read()
    }
    if (read > SPACE_INT) {
        reset()
    }
    return if (neg) -ret else ret
}