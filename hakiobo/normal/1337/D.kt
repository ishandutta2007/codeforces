import kotlin.math.absoluteValue
import kotlin.math.min


fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    repeat(numCases) {
        br.readLine()
        val red = br.readLine().split(' ').map { it.toInt() shl 1 }.sorted()
        val green = br.readLine().split(' ').map { it.toInt() shl 1 }.sorted()
        val blue = br.readLine().split(' ').map { it.toInt() shl 1 }.sorted()
        fun findClosestAbove(target: Int, list: List<Int>): Int {
            var low = 0
            var high = list.size
            var best = list.last()
            var mid = (low + high) / 2
            while (low != high) {
                when {
                    list[mid] > target -> {
                        high = mid
                        best = list[mid]
                    }
                    list[mid] < target -> {
                        low = mid + 1
                    }
                    else -> {
                        return target
                    }
                }
                mid = (low + high) / 2
            }
            return best
        }

        fun findClosestBelow(target: Int, list: List<Int>): Int {
            var low = 0
            var high = list.size
            var best = list.first()
            var mid = (low + high) / 2
            while (low != high) {
                when {
                    list[mid] > target -> {
                        high = mid
                    }
                    list[mid] < target -> {
                        low = mid + 1
                        best = list[mid]
                    }
                    else -> {
                        return target
                    }
                }
                mid = (low + high) / 2
            }
            return best
        }

        fun calcBest(w1: Int, w2: Int, list: List<Int>): Int {
            val target = (w1 shr 1) + (w2 shr 1)
            val c1 = findClosestAbove(target, list)
            val c2 = findClosestBelow(target, list)
            return if ((c1 - target).absoluteValue < (c2 - target).absoluteValue) c1 else c2
        }

        fun calcScore(r: Int, g: Int, b: Int): Long {
            val rt = (r shr 1).toLong()
            val gt = (g shr 1).toLong()
            val bt = (b shr 1).toLong()
            val d1 = rt - gt
            val d2 = gt - bt
            val d3 = bt - rt
            return d1 * d1 + d2 * d2 + d3 * d3
        }

        var best = Long.MAX_VALUE
        for (rWeight in red) {
            val gAbove = findClosestAbove(rWeight, green)
            best = min(best, calcScore(rWeight, gAbove, calcBest(rWeight, gAbove, blue)))
            val gBelow = findClosestBelow(rWeight, green)
            best = min(best, calcScore(rWeight, gBelow, calcBest(rWeight, gBelow, blue)))
            val bAbove = findClosestAbove(rWeight, blue)
            best = min(best, calcScore(rWeight, calcBest(rWeight, bAbove, green), bAbove))
            val bBelow = findClosestBelow(rWeight, blue)
            best = min(best, calcScore(rWeight, calcBest(rWeight, bBelow, green), bBelow))
        }
        for (gWeight in green) {
            val rAbove = findClosestAbove(gWeight, red)
            best = min(best, calcScore(gWeight, rAbove, calcBest(gWeight, rAbove, blue)))
            val rBelow = findClosestBelow(gWeight, red)
            best = min(best, calcScore(gWeight, rBelow, calcBest(gWeight, rBelow, blue)))
            val bAbove = findClosestAbove(gWeight, blue)
            best = min(best, calcScore(gWeight, calcBest(gWeight, bAbove, red), bAbove))
            val bBelow = findClosestBelow(gWeight, blue)
            best = min(best, calcScore(gWeight, calcBest(gWeight, bBelow, red), bBelow))
        }
        for (bWeight in blue) {
            val gAbove = findClosestAbove(bWeight, green)
            best = min(best, calcScore(bWeight, gAbove, calcBest(bWeight, gAbove, red)))
            val gBelow = findClosestBelow(bWeight, green)
            best = min(best, calcScore(bWeight, gBelow, calcBest(bWeight, gBelow, red)))
            val rAbove = findClosestAbove(bWeight, red)
            best = min(best, calcScore(bWeight, calcBest(bWeight, rAbove, green), rAbove))
            val rBelow = findClosestBelow(bWeight, red)
            best = min(best, calcScore(bWeight, calcBest(bWeight, rBelow, green), rBelow))
        }
        sb.append(best)
        sb.append('\n')
    }
    print(sb)
}