import java.io.*
import java.util.*

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Egor Kulikov (egor@egork.net)
 */
object programkt {
    @JvmStatic
    fun main(args: Array<String>) {
        val inputStream = System.`in`
        val outputStream: OutputStream = System.out
        val `in` = InputReader(inputStream)
        val out = OutputWriter(outputStream)
        val solver = TaskG()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class TaskG {
        fun solve(testNumber: Int, `in`: InputReader, out: OutputWriter) {
            val n = `in`.readInt()
            val divisors: Array<MutableList<Int>?> = arrayOfNulls<MutableList<Int>>(n + 1)
            for (i in 0 until n) {
                divisors[i + 1] = ArrayList()
            }
            val score = IntArray(n + 1)
            for (i in 1..n) {
                var j = 2 * i
                while (j <= n) {
                    score[j]++
                    divisors[j]!!.add(i)
                    j += i
                }
            }
            val queue: NavigableSet<Int> = TreeSet(Comparator { x: Int, y: Int -> if (score[x] != score[y]) score[y] - score[x] else x - y })
            for (i in 1..n) {
                queue.add(i)
            }
            var curScore: Long = 0
            val red = BooleanArray(n + 1)
            val answer = LongArray(n)
            for (i in 0 until n) {
                val cur = queue.pollFirst()
                red[cur] = true
                curScore += score[cur]
                answer[i] = curScore
                var j = 2 * cur
                while (j <= n) {
                    if (!red[j]) {
                        queue.remove(j)
                        score[j]--
                        queue.add(j)
                    }
                    j += cur
                }
                for (j in divisors[cur]!!) {
                    if (!red[j]) {
                        queue.remove(j)
                        score[j]--
                        queue.add(j)
                    }
                }
            }
            out.printLine(answer)
        }
    }

    internal class InputReader(private val stream: InputStream) {
        private val buf = ByteArray(1024)
        private var curChar = 0
        private var numChars = 0
        private val filter: SpaceCharFilter? = null
        fun read(): Int {
            if (numChars == -1) {
                throw InputMismatchException()
            }
            if (curChar >= numChars) {
                curChar = 0
                numChars = try {
                    stream.read(buf)
                } catch (e: IOException) {
                    throw InputMismatchException()
                }
                if (numChars <= 0) {
                    return -1
                }
            }
            return buf[curChar++].toInt()
        }

        fun readInt(): Int {
            var c = read()
            while (isSpaceChar(c)) {
                c = read()
            }
            var sgn = 1
            if (c == '-'.toInt()) {
                sgn = -1
                c = read()
            }
            var res = 0
            do {
                if (c < '0'.toInt() || c > '9'.toInt()) {
                    throw InputMismatchException()
                }
                res *= 10
                res += c - '0'.toInt()
                c = read()
            } while (!isSpaceChar(c))
            return res * sgn
        }

        fun isSpaceChar(c: Int): Boolean {
            return filter?.isSpaceChar(c) ?: isWhitespace(c)
        }

        interface SpaceCharFilter {
            fun isSpaceChar(ch: Int): Boolean
        }

        companion object {
            fun isWhitespace(c: Int): Boolean {
                return c == ' '.toInt() || c == '\n'.toInt() || c == '\r'.toInt() || c == '\t'.toInt() || c == -1
            }
        }

    }

    internal class OutputWriter {
        private val writer: PrintWriter

        constructor(outputStream: OutputStream?) {
            writer = PrintWriter(BufferedWriter(OutputStreamWriter(outputStream)))
        }

        constructor(writer: Writer?) {
            this.writer = PrintWriter(writer)
        }

        fun print(array: LongArray) {
            for (i in array.indices) {
                if (i != 0) {
                    writer.print(' ')
                }
                writer.print(array[i])
            }
        }

        fun printLine(array: LongArray) {
            print(array)
            writer.println()
        }

        fun close() {
            writer.close()
        }
    }
}