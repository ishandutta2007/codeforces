import java.io.BufferedReader
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val m = br.readInt()
        val k = br.readInt()

        val toIndex = Array(n) { i -> Array(k) { j -> IntArray(2) { l -> ((i * k + j) shl 1) or l } } }
        val cons = Array(n * k * 2) { mutableListOf<Int>() }
        for (node in 0 until n) {
            for (value in 0 until k) {
                val thisIndexNo = toIndex[node][value][0]
                val thisIndexYes = toIndex[node][value][1]

                if (node != 0) {
                    val prevIndexNo = toIndex[node - 1][value][0]
                    val prevIndexYes = toIndex[node - 1][value][1]
                    // nondecreasing sequence condition
                    cons[prevIndexYes].add(thisIndexYes) // if the previous number was greater than value, then this number must be too
                    cons[thisIndexNo].add(prevIndexNo) // if this number is not greater than the value, the previous number can't be either
                }
                if (value != 0) { // this number being greater than a larger number implies it's also greater than a smaller number
                    val lowerValIndexNo = toIndex[node][value - 1][0]
                    val lowerValIndexYes = toIndex[node][value - 1][1]
                    cons[thisIndexYes].add(lowerValIndexYes)
                    cons[lowerValIndexNo].add(thisIndexNo)
                } else {
                    cons[thisIndexNo].add(thisIndexYes) // number must always be greater than 0
                }
            }
        }
        repeat(m) {
            when (br.readInt()) {
                1 -> {
                    val i = br.readInt() - 1
                    val x = br.readInt()
                    if (x == k) { // means the number can't be greater than k - 1
                        val yesIdx = toIndex[i][x - 1][1]
                        val noIdx = toIndex[i][x - 1][0]
                        cons[yesIdx].add(noIdx)
                    } else { // if the number is greater than x - 1, it's also greater than x
                        val lowerYesIdx = toIndex[i][x - 1][1]
                        val lowerNoIdx = toIndex[i][x - 1][0]
                        val higherYesIdx = toIndex[i][x][1]
                        val higherNoIdx = toIndex[i][x][0]
                        cons[lowerYesIdx].add(higherYesIdx)
                        cons[higherNoIdx].add(lowerNoIdx)
                    }
                }
                2 -> { // ai + aj <= x
                    val i = br.readInt() - 1
                    val j = br.readInt() - 1
                    val x = br.readInt()
                    for (largest in 1..k) {
                        val largerYesIdx = toIndex[j][largest - 1][1] // aj >= largest
                        val largerNoIdx = toIndex[j][largest - 1][0] // aj < largest
                        val otherMax = x - largest
                        if (otherMax == 0) {
                            cons[largerYesIdx].add(largerNoIdx)
                        } else if (otherMax in 1 until k) {
                            val smallerYesIdx = toIndex[i][otherMax][1]
                            val smallerNoIdx = toIndex[i][otherMax][0]
                            cons[largerYesIdx].add(smallerNoIdx)
                            cons[smallerYesIdx].add(largerNoIdx)
                        }
                    }
                }
                3 -> { // ai + aj >= x
                    val i = br.readInt() - 1
                    val j = br.readInt() - 1
                    val x = br.readInt()
                    for (smaller in 1..k) {
                        val largerYesIdx = toIndex[i][smaller - 1][1] // ai >= smaller
                        val largerNoIdx = toIndex[i][smaller - 1][0] // ai < smaller
                        // ai < smaller -> ai > x - smaller
                        val otherMin = x - smaller
                        if (otherMin == k) {
                            cons[largerNoIdx].add(largerYesIdx)
                        } else if (otherMin in 1 until k) {
                            val smallerYesIdx = toIndex[j][otherMin][1]
                            val smallerNoIdx = toIndex[j][otherMin][0]
                            cons[largerNoIdx].add(smallerYesIdx)
                            cons[smallerNoIdx].add(largerYesIdx)
                        }
                    }
                }
            }
        }
        val order = IntArray(n * k * 2)
        val vis = BooleanArray(n * k * 2)
        var orderIdx = 0
        fun dfs(node: Int) {
            vis[node] = true
            for (adj in cons[node]) {
                if (!vis[adj]) {
                    dfs(adj)
                }
            }
            order[orderIdx++] = node
        }
        for (node in 0 until n * k * 2) {
            if (!vis[node]) {
                dfs(node)
            }
        }
        var compCount = 0
        val components = IntArray(n * k * 2) { -1 }
        fun dfs2(node: Int) {
            components[node] = compCount
            val xNode = node xor 1
            for (xAdj in cons[xNode]) {
                val adj = 1 xor xAdj
                if (components[adj] == -1) {
                    dfs2(adj)
                }
            }
        }
        for (i in order.lastIndex downTo 0) {
            val node = order[i]
            if (components[node] == -1) {
                dfs2(node)
                compCount++
            }
        }
        var good = true
        for (i in 0 until n * k) {
            val no = i * 2
            val yes = no + 1
            if (components[no] == components[yes]) {
                good = false
            }
        }
        if (good) {
            val componentToNodes = Array(compCount) { mutableListOf<Int>() }
            val componentOuts = IntArray(compCount)
            for (node in 0 until 2 * n * k) {
                val component = components[node]
                componentToNodes[component].add(node)
                for (adj in cons[node]) {
                    if (components[adj] != component) {
                        componentOuts[component]++
                    }
                }
            }
            val queue = IntArray(compCount)
            var inIdx = 0
            var outIdx = 0
            for (component in 0 until compCount) {
                if (componentOuts[component] == 0) {
                    queue[inIdx++] = component
                }
            }
            val status = IntArray(n * k) { -1 }
            while (outIdx < inIdx) {
                val component = queue[outIdx++]
                for (node in componentToNodes[component]) {
                    val isYes = node and 1
                    val type = node shr 1
                    if (status[type] == -1) {
                        status[type] = isYes
                        for (xAdj in cons[node xor 1]) {
                            val adj = 1 xor xAdj
                            if (components[adj] != component) {
                                if (--componentOuts[components[adj]] == 0) {
                                    queue[inIdx++] = components[adj]
                                }
                            }
                        }
                    }
                }
            }
            val ans = IntArray(n) { k }
            for (i in 0 until n * k) {
                val a = status[i]
                val index = i / k
                val value = i % k
                if (a == 0) {
                    ans[index] = min(ans[index], value)
                }
            }
            bw.appendLine(ans.joinToString(" "))
        } else {
            bw.appendLine("-1")
        }
    }
    bw.flush()
}

//private inline fun Int.node(k: Int) = this / (2 * k)
//private inline fun Int.value(k: Int) = (this shr 1) % k
//private inline fun Int.truth() = this and 1


//private data class ConstraintIndex(val node: Int, val value: Int, val negated: Int)

private const val SPACE_INT = ' '.toInt()
private const val ZERO_INT = '0'.toInt()
private const val NL_INT = '\n'.toInt()

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