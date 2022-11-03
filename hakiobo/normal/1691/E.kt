import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val segments = mutableListOf<GroupSegment>()

        for (i in 0 until n) {
            val c = br.readInt()
            val l = br.readInt()
            val r = br.readInt()
            segments += GroupSegment(c, l, 1, i)
            segments += GroupSegment(c, r, -1, i)
        }
        val groups = GroupUF(n)
        segments.sort()
        val curs = IntArray(2)
        val groupData = mutableListOf<Int>()
        for ((c, _, starting, idx) in segments) {
            if (starting == 1) {
                var cur = groups.find(idx)
                if (curs[c]++ == 0) {
                    for (g in groupData) {
                        if (groups.getActiveCount(g) != 0) {
                            cur = groups.union(cur, g)
                        }
                    }
                    groupData.clear()
                    groupData += cur
                } else if (curs[c xor 1] == 0) {
                    groupData += cur
                } else {
                    groupData[0] = groups.union(groupData[0], cur)
                }
                groups.adjustActiveCount(cur, 1)
            } else {
                curs[c]--
                groups.adjustActiveCount(idx, -1)
            }

        }
        bw.appendLine(groups.numGroups.toString())
    }
    bw.flush()
}


private data class GroupSegment(val color: Int, val spot: Int, val starting: Int, val idx: Int) :
    Comparable<GroupSegment> {
    override fun compareTo(other: GroupSegment): Int {
        return if (this.spot == other.spot) {
            other.starting.compareTo(this.starting)
        } else {
            this.spot.compareTo(other.spot)
        }
    }

}

private class GroupUF(val n: Int) {
    val reps = IntArray(n) { it }
    val rank = IntArray(n)
    val activeCounts = IntArray(n)
    var numGroups = n
    fun find(a: Int): Int {
        var k = a
        var d = reps[a]
        while (d != k) {
            reps[k] = reps[d]
            k = d
            d = reps[k]
        }
        return k
    }

    fun adjustActiveCount(a: Int, delta: Int) {
        activeCounts[find(a)] += delta
    }

    fun getActiveCount(a: Int) = activeCounts[find(a)]

    fun union(a: Int, b: Int): Int {
        val u = find(a)
        val v = find(b)
        numGroups--
        return if (u == v) {
            numGroups++
            u
        } else if (rank[u] > rank[v]) {
            activeCounts[u] += activeCounts[v]
            reps[v] = u
            u
        } else if (rank[u] < rank[v]) {
            reps[u] = v
            activeCounts[v] += activeCounts[u]
            v
        } else {
            reps[v] = u
            rank[u]++
            activeCounts[u] += activeCounts[v]
            u
        }
    }
}

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