import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val n = br.readInt()
    var cards = IntArray(n) { br.readInt() }
    fun performMove(sizes: List<Int>): IntArray {
        if (sizes.sum() != n) throw IllegalArgumentException()
        val new = IntArray(n)
        var pre = 0
        for (s in sizes) {
            for (y in 0 until s) {
                new[n - pre - s + y] = cards[pre + y]
            }
            pre += s
        }
        return new
    }

    fun isInOrder(c: IntArray): Boolean {
        for (x in 0 until n) {
            if (c[x] != x + 1) {
                return false
            }
        }
        return true
    }

    val moves = mutableListOf<List<Int>>()
    while (!isInOrder(cards)) {
        val oneIdx = cards.indexOf(1)
        when (oneIdx) {
            0 -> {
                val sizes = mutableListOf<Int>()
                var firstOutOfOrder = 1
                while (cards[firstOutOfOrder] == firstOutOfOrder + 1) {
                    firstOutOfOrder++
                }
                sizes += firstOutOfOrder
                val next = cards.indexOf(cards[firstOutOfOrder] - 1)
//                sizes += next - firstOutOfOrder
                var t = firstOutOfOrder + 1
                while (cards[t] == cards[firstOutOfOrder] + t - firstOutOfOrder) {
                    t++
                }
                sizes += t - firstOutOfOrder
                sizes += next + 1 - t
                if (next != n - 1) {
                    sizes += n - next - 1
                }
//                val next = cards.indexOf(firstOutOfOrder + 1)
//                val next2 = cards.indexOf(firstOutOfOrder + 2)
//                if(next2 == next + 1){
//
//                } else if(next2 < next){
//
//                }
//                sizes += n - firstOutOfOrder
//                sizes += (next - firstOutOfOrder)
//                if (next != n - 1) {
//                    sizes += n - next - 1
//                }
                moves += sizes
                cards = performMove(sizes)
            }
            else -> {
                val sizes = mutableListOf<Int>()
                var firstIdxOutOfOrder = oneIdx + 1
                var firstNumOutOfOrder = 2
                while (firstIdxOutOfOrder != n && cards[firstIdxOutOfOrder] == firstNumOutOfOrder) {
                    firstIdxOutOfOrder++
                    firstNumOutOfOrder++
                }
                if (firstIdxOutOfOrder == n) {
                    var left = oneIdx
                    sizes += n - oneIdx
                    while (true) {
                        val next = cards.indexOf(firstNumOutOfOrder)
                        if (next == 0) {
                            sizes += left
                            break
                        }
                        firstNumOutOfOrder++
                        var tI = next + 1
                        sizes += left - next
                        while (tI < left && cards[tI] == firstNumOutOfOrder) {
                            tI++
                            firstNumOutOfOrder++
                        }
                        if (tI != left) {
                            sizes += next
                            break
                        }

                        left = next
                    }
                    sizes.reverse()
                } else {
                    sizes += oneIdx
                    sizes += n - oneIdx
                }
                moves += sizes
                cards = performMove(sizes)
            }
        }
    }
    sb.append(moves.size).append("\n")
    for (sizes in moves) {
        sb.append(sizes.size).append(" ").append(sizes.joinToString(" ")).append("\n")
    }
    print(sb)
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