
import java.lang.StringBuilder
import java.lang.System.`in`
import java.util.*
import kotlin.math.min

fun main() {
    val br = `in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    repeat(numCases) {
        val permSize = br.readLine().toInt()
        val permutation = br.readLine().split(' ').map { it.toInt() - 1 }
        val colors = br.readLine().split(' ').map(String::toInt)
        val processed = BooleanArray(permSize)
        var minSize = permSize
        repeat(permSize) { start ->
            if (!processed[start]) {
                processed[start] = true
                var subSize = 1
                val startColor = colors[start]
                var allSameColor = true
                var cur = start
                while (permutation[cur] != start) {
                    subSize++
                    cur = permutation[cur]
                    if (startColor != colors[cur]) {
                        allSameColor = false
                    }
                    processed[cur] = true
                }
                if (allSameColor) {
                    minSize = 1
                } else {
                    minSize = min(subSize, minSize)
                    val factors = getNonTrivialFactors(subSize)
                    for (f in factors) {
                        if (f >= minSize) {
                            break
                        }
                        val bad = BooleanArray(f)
                        val subColors = IntArray(f)
                        cur = start
                        repeat(subSize) { id ->
                            if (id < f) {
                                subColors[id] = colors[cur]
                            } else {
                                val modID = id % f
                                bad[modID] = bad[modID] || subColors[modID] != colors[cur]
                            }
                            cur = permutation[cur]
                        }
                        repeat(f) { b ->
                            if (!bad[b]) {
                                minSize = f
                            }
                        }
                    }
                }
            }
        }
        sb.append(minSize)
        sb.append('\n')
    }
    print(sb)
}

private fun getNonTrivialFactors(n: Int): Set<Int> {
    val factors = TreeSet<Int>()
    var i = 2
    while (i * i <= n) {
        if (n % i == 0) {
            factors.add(i)
            factors.add(n / i)
        }
        i++
    }
    return factors
}