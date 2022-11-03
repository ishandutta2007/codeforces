import java.io.BufferedReader

private data class Robot(val start: Int, val right: Boolean, val idx: Int) : Comparable<Robot> {
    val leftStart: Int
        get() {
            return if (right) {
                m + m - start
            } else {
                start
            }
        }
    val rightStart: Int
        get() {
            return if (right) {
                start
            } else {
                -start
            }
        }

    override fun compareTo(other: Robot): Int {
        return start.compareTo(other.start)
    }

    companion object {
        var m = 0
    }
}

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readLine().toInt()
    repeat(t) {
        val (n, m) = br.readLine().split(" ").map { it.toInt() }
        Robot.m = m
        val robots = run {
            val starts = IntArray(n) { br.readInt() }
            val rights = br.readLine().split(" ").map { it == "R" }
            List(n) { Robot(starts[it], rights[it], it) }.sorted()
        }
        val answers = IntArray(n) { -1 }
        val lists = List(2) { mutableListOf<Int>() }
        for (x in 0 until n) {
            val robot = robots[x]
            val listId = robot.start and 1
            if (lists[listId].isNotEmpty()) {
                if (robot.right) {
                    lists[listId] += x
                } else {
                    val other = robots[lists[listId].removeLast()]
                    val time = (robot.leftStart - other.rightStart) shr 1
                    answers[robot.idx] = time
                    answers[other.idx] = time
                }
            } else {
                lists[listId] += x
            }
        }
        for (listIdx in 0 until 2) {
            val list = lists[listIdx]
            while (list.size >= 2) {
                val r1 = robots[list.removeLast()]
                val r2 = robots[list.removeLast()]
                val time = (r1.leftStart - r2.rightStart) shr 1
                answers[r1.idx] = time
                answers[r2.idx] = time
            }
        }
        sb.appendLine(answers.joinToString(" "))
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