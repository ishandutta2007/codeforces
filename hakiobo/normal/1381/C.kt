import java.io.BufferedReader
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val x = br.readInt()
        val y = br.readInt()
        val guess = IntArray(n) { br.readInt() - 1 }
        val ans = IntArray(n)
        var moved = y - x
        val counts = IntArray(n + 1)
        for (i in 0 until n) {
            counts[guess[i]]++
        }
        var notIn = 0
        while (counts[notIn] != 0) {
            notIn++
        }

        var numCorrect = 0
        if (moved == 1) {
            if (y == n) {
                sb.append("NO\n")
            } else {
                val first = guess.first()
                var second = -1
                for (i in guess.indices) {
                    val color = guess[i]
                    if (color != first) {
                        second = color
                        ans[i] = notIn + 1
                        ans[0] = color + 1
                        break
                    }
                }
                if (second == -1) {
                    sb.append("NO\n")
                } else {
                    sb.append("YES\n")
                    for (i in 1 until n) {
                        if (ans[i] == 0 && numCorrect < x) {
                            ans[i] = guess[i] + 1
                            numCorrect++
                        } else {
                            ans[i] = notIn + 1
                        }
                    }
                    sb.append(ans.joinToString(" ")).append('\n')
                }
            }
        } else {
            if (y == n || moved and 1 == 0) {
                var sum = 0
                val spot = IntArray(n + 1) { -1 }
                val important = IntArray(moved)

                for (i in 0..n) {
                    val toUse = min(min(counts[i], moved - sum), moved shr 1)
                    if (toUse != 0) {
                        spot[i] = sum
                        for (j in sum until sum + toUse) {
                            important[j] = i
                        }
                        sum += toUse
                    }
                }


                if (sum == moved) {
                    sb.append("YES\n")
                    for (i in 0 until n) {
                        val color = guess[i]
                        ans[i] = if (spot[color] != -1 && spot[color] != moved && important[spot[color]] == color) {
                            spot[color]++
                            important[(spot[color] - 1 + (moved shr 1)) % moved] + 1
                        } else if (numCorrect < x) {
                            numCorrect++
                            color + 1
                        } else {
                            notIn + 1
                        }
                    }
                    sb.append(ans.joinToString(" ")).append('\n')
                } else {
                    sb.append("NO\n")
                }
            } else {
                moved++
                var sum = 0
                val spot = IntArray(n + 1) { -1 }
                val important = IntArray(moved)
                var bigOne = -1
                for (i in 0..n) {
                    val toUse = min(min(counts[i], moved - sum), moved shr 1)
                    if (toUse != 0) {
                        if (bigOne == -1 && (toUse == moved shr 1 || toUse + sum == moved)) {
                            bigOne = i
                        }
                        spot[i] = sum
                        for (j in sum until sum + toUse) {
                            important[j] = i
                        }
                        sum += toUse
                    }
                }

                if (sum == moved) {
                    sb.append("YES\n")
                    for (i in 0 until n) {
                        val color = guess[i]
                        ans[i] = if (spot[color] != -1 && spot[color] != moved && important[spot[color]] == color) {
                            spot[color]++
                            if (bigOne == color) {
                                bigOne = -1
                                notIn + 1
                            } else {
                                important[(spot[color] - 1 + (moved shr 1)) % moved] + 1
                            }
                        } else if (numCorrect < x) {
                            numCorrect++
                            color + 1
                        } else {
                            notIn + 1
                        }
                    }
                    sb.append(ans.joinToString(" ")).append('\n')
                } else {
                    sb.append("NO\n")
                }
            }
        }
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