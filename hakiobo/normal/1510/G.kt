import java.io.PrintWriter
import java.util.*
import kotlin.math.max
import kotlin.math.min

private inline val Triple<Node, Int, Int>.depth
    get() = third
private inline val Triple<Node, Int, Int>.score
    get() = second
private inline val Triple<Node, Int, Int>.node
    get() = first

fun main() = tm {
    if (false) {
        println(8)
        repeat(8) {
            println("8 ${it + 1}")
            println("1 2 1 4 5 5 7")
        }
        return@tm
    }
    fun ans(l: List<Int>) {
        println(l.size - 1)
        println(l.joinToString(" "))
    }

    repeat(readInt()) { _ ->
        val (nNodes, visCities) = readIntArray(2)
        val nodes = Array(nNodes) { Node(it + 1) }
        for (i in 1 until nNodes) {
            nodes[readInt() - 1].childs += nodes[i]
        }
        val (ms, md) = runDP(nodes.first())
        nodes.forEach { it.dp.sortBy { c -> c.third } }
        //printTree(nodes.first(), ms, md)
        val list = ArrayList<Int>(2 * visCities)
        solve(nodes.first(), list, visCities, visCities, visCities)
        ans(list)
    }
}

private fun printTree(n: Node, numNodesIncludingSelf: Int, depth: Int, d: Int = 0): Unit = tm {
    println("${"  ".repeat(d)}${n.id}: ${n.childs.size} children, $numNodesIncludingSelf score, $depth maxDepth")
    for ((c, sc, de) in n.dp) {
        printTree(c, sc, de, d + 1)
    }
}

private fun solve(
    first: Node,
    list: MutableList<Int>,
    needSize: Int,
    wantSize: Int,
    maxToVisit: Int,
    fullTree: Boolean = false,
    seen: MutableSet<Int> = HashSet()
) {
    list += first.id
    seen += first.id
    var rem = wantSize - seen.size
    if (rem == 0 || maxToVisit == 0) {
        return
    }
    rem = min(rem, maxToVisit)
    if (rem > first.childNodes || fullTree) {
        first.childs.forEach {
            solve(it, list, needSize, wantSize, maxToVisit, true, seen)
            list += first.id
        }
    } else if (first.dp.isNotEmpty()) {
        val longest = first.dp.last()
        val needRemaining = longest.score
        for ((node, score, maxDepth) in first.dp) {
            if (rem <= longest.score) {
                solve(longest.node, list, needSize, wantSize, maxToVisit - 1, false, seen)
                if (seen.size != needSize) {
                    list += first.id
                }
                break
            }
            solve(node, list, needSize, wantSize, rem - needRemaining - 1, rem - score >= needRemaining, seen)
            list += first.id
            rem -= node.childNodes + 1
        }
    }
}

private fun runDP(n: Node): Pair<Int, Int> {
    var score = 1
    var maxDepth = 1
    for (child in n.childs) {
        val (cs, cd) = runDP(child)
        n.dp += Triple(child, cs, cd)
        score += cs
        maxDepth = max(maxDepth, cd + 1)
    }
    n.childNodes = score - 1
    return score to maxDepth
}

private class Node(val id: Int) {
    val childs = ArrayList<Node>()

    // node, size, depth
    val dp = ArrayList<Triple<Node, Int, Int>>()
    var childNodes = 0

    override fun toString(): String {
        return "Node $id"
    }
}

private inline fun <T> tm(block: GuideIO.() -> T) {
    itm(block)
}

private lateinit var Guideio: GuideIO
private var refs = 0
private inline fun <T> itm(block: GuideIO.() -> T): T {
    if (refs++ == 0) {
        Locale.setDefault(Locale.US)
        Guideio = GuideIO()
    }
    val ret = block(Guideio)
    if (--refs == 0) {
        Guideio.close()
    }
    return ret
}

private class GuideIO : PrintWriter(System.out.bufferedWriter(), false) {
    private val r = System.`in`.bufferedReader()
    private var tk = StringTokenizer("")

    fun readWord(): String {
        while (!tk.hasMoreTokens()) {
            tk = StringTokenizer(r.readLine() ?: return "", " ")
        }
        return tk.nextToken()
    }

    fun clearLine() {
        tk = StringTokenizer("")
    }

    fun readLine() = r.readLine()
    fun readInt() = readWord().toInt()
    fun readDouble() = readWord().toDouble()
    fun readLong() = readWord().toLong()

    fun readIntArray(n: Int = readInt()) = IntArray(n) { readInt() }
    fun readLongArray(n: Int = readInt()) = LongArray(n) { readLong() }
    fun readDoubleArray(n: Int = readInt()) = DoubleArray(n) { readDouble() }
}