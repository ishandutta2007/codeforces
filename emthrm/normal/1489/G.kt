// https://github.com/da-louis/ac-library-kt/blob/master/src/main/kotlin/jp/atcoder/library/kotlin/dsu/DSU.kt
/**
 * Disjoint set union.
 *
 * convert from [AtCoderLibraryForJava - DSU](https://github.com/NASU41/AtCoderLibraryForJava/blob/8b3a3b599790a9ca8c7dd92e036af4ddc5be1b05/DSU/DSU.java)
 */
class DSU(private val n: Int) {
    private val parentOrSize: IntArray = IntArray(n) { -1 }

    /**
     * Merge nodes.
     */
    fun merge(a: Int, b: Int): Int {
        // if (a !in 0 until n) throw IndexOutOfBoundsException("a=$a")
        // if (b !in 0 until n) throw IndexOutOfBoundsException("b=$b")
        var x = leader(a)
        var y = leader(b)
        if (x == y) return x
        if (-parentOrSize[x] < -parentOrSize[y]) {
            val tmp = x
            x = y
            y = tmp
        }
        parentOrSize[x] += parentOrSize[y]
        parentOrSize[y] = x
        return x
    }

    /**
     * True if two nodes are connected.
     */
    fun same(a: Int, b: Int): Boolean {
        // if (a !in 0 until n) throw IndexOutOfBoundsException("a=$a")
        // if (b !in 0 until n) throw IndexOutOfBoundsException("b=$b")
        return leader(a) == leader(b)
    }

    /**
     * Get its leader node.
     */
    fun leader(a: Int): Int {
        return if (parentOrSize[a] < 0) {
            a
        } else {
            parentOrSize[a] = leader(parentOrSize[a])
            parentOrSize[a]
        }
    }

    /**
     * A group's size.
     */
    fun size(a: Int): Int {
        // if (a !in 0 until n) throw IndexOutOfBoundsException("" + a)
        return -parentOrSize[leader(a)]
    }

    /**
     * Group by leader.
     */
    fun groups(): ArrayList<ArrayList<Int>> {
        val leaderBuf = IntArray(n)
        val groupSize = IntArray(n)
        for (i in 0 until n) {
            leaderBuf[i] = leader(i)
            groupSize[leaderBuf[i]]++
        }
        val result = ArrayList<ArrayList<Int>>(n)
        for (i in 0 until n) {
            result.add(ArrayList(groupSize[i]))
        }
        for (i in 0 until n) {
            result[leaderBuf[i]].add(i)
        }
        result.removeIf { it.isEmpty() }
        return result
    }
}

fun main(args: Array<String>) {
    var (n, m) = readLine()!!.split(" ").map{ it.toInt() }
    var a = readLine()!!.split(" ").map{ it.toLong() }
    var ord = Array(n) { it }
    ord.sortBy { a[it] }
    var offer = Array<Triple<Int, Int, Long>>(m) { Triple(-1, -1, 0L) }
    for (i in 0 until m) {
        var xyw = readLine()!!.split(" ")
        offer[i] = Triple(xyw[0].toInt() - 1, xyw[1].toInt() - 1, xyw[2].toLong())
    }
    offer.sortBy { it.third }
    var dsu = DSU(n)
    var index = 0
    var ans = 0L
    for (i in 1 until n) {
        var cost = a[ord[0]] + a[ord[i]]
        while (index < m && offer[index].third < cost) {
            if (!dsu.same(offer[index].first, offer[index].second)) {
                dsu.merge(offer[index].first, offer[index].second)
                ans += offer[index].third
            }
            ++index
        }
        if (!dsu.same(ord[0], ord[i])) {
            dsu.merge(ord[0], ord[i])
            ans += cost
        }
    }
    println(ans)
}