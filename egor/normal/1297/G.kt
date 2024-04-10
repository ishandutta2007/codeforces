
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
        val outputStream = System.out
        val `in` = InputReader(inputStream)
        val out = OutputWriter(outputStream)
        val solver = TaskG()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class TaskG {
        var p2: Int = 0
        var p3: Int = 0
        var p5: Int = 0
        var p7: Int = 0
        var res: MutableList<Array<Array<Array<LongArray>>>> = ArrayList()
        var vals = arrayOf(intArrayOf(0, 0, 0, 0), intArrayOf(1, 0, 0, 0), intArrayOf(0, 1, 0, 0), intArrayOf(2, 0, 0, 0), intArrayOf(0, 0, 1, 0), intArrayOf(1, 1, 0, 0), intArrayOf(0, 0, 0, 1), intArrayOf(3, 0, 0, 0), intArrayOf(0, 2, 0, 0))

        fun qty(len: Int, a2: Int, a3: Int, a5: Int, a7: Int): Long {
            while (res.size <= len) {
                val level = Array(p2 + 1) { Array(p3 + 1) { Array(p5 + 1) { LongArray(p7 + 1) } } }
                ArrayUtils.fill(level, -1)
                res.add(level)
            }
            val slice = res[len]
            if (slice[a2][a3][a5][a7] != -1.toLong()) {
                return slice[a2][a3][a5][a7]
            }
            if (len == 0) {
                slice[a2][a3][a5][a7] = (if (a2 == 0 && a3 == 0 && a5 == 0 && a7 == 0) 1 else 0).toLong()
                return slice[a2][a3][a5][a7]
            }
            slice[a2][a3][a5][a7] = 0
            for (v in vals) {
                if (a2 >= v[0] && a3 >= v[1] && a5 >= v[2] && a7 >= v[3]) {
                    slice[a2][a3][a5][a7] += qty(len - 1, a2 - v[0], a3 - v[1], a5 - v[2], a7 - v[3])
                }
            }
            return slice[a2][a3][a5][a7]
        }

        fun solve(testNumber: Int, `in`: InputReader, out: OutputWriter) {
            var m = `in`.readInt()
            var k = `in`.readLong() - 1
            p2 = 0
            p3 = 0
            p5 = 0
            p7 = 0
            while (m % 2 == 0) {
                m /= 2
                p2++
            }
            while (m % 3 == 0) {
                m /= 3
                p3++
            }
            while (m % 5 == 0) {
                m /= 5
                p5++
            }
            while (m % 7 == 0) {
                m /= 7
                p7++
            }
            if (m != 1) {
                out.printLine(-1)
                return
            }
            var len = 1
            while (true) {
                var q = qty(len, p2, p3, p5, p7)
                if (q <= k) {
                    k -= q
                    len++
                    continue
                }
                val answer = CharArray(len)
                for (i in 0 until len) {
                    for (j in 0..8) {
                        val v = vals[j]
                        if (p2 >= v[0] && p3 >= v[1] && p5 >= v[2] && p7 >= v[3]) {
                            q = qty(len - i - 1, p2 - v[0], p3 - v[1], p5 - v[2], p7 - v[3])
                            if (q <= k) {
                                k -= q
                                continue
                            }
                            answer[i] = (j + '1'.toInt()).toChar()
                            p2 -= v[0]
                            p3 -= v[1]
                            p5 -= v[2]
                            p7 -= v[3]
                            break
                        }
                    }
                }
                out.printLine(answer)
                return
                len++
            }
        }

    }

    internal class InputReader(private val stream: InputStream) {
        private val buf = ByteArray(1024)
        private var curChar: Int = 0
        private var numChars: Int = 0
        private val filter: InputReader.SpaceCharFilter? = null

        fun read(): Int {
            if (numChars == -1) {
                throw InputMismatchException()
            }
            if (curChar >= numChars) {
                curChar = 0
                try {
                    numChars = stream.read(buf)
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

        fun readLong(): Long {
            var c = read()
            while (isSpaceChar(c)) {
                c = read()
            }
            var sgn = 1
            if (c == '-'.toInt()) {
                sgn = -1
                c = read()
            }
            var res: Long = 0
            do {
                if (c < '0'.toInt() || c > '9'.toInt()) {
                    throw InputMismatchException()
                }
                res *= 10
                res += (c - '0'.toInt()).toLong()
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

        constructor(outputStream: OutputStream) {
            writer = PrintWriter(BufferedWriter(OutputStreamWriter(outputStream)))
        }

        constructor(writer: Writer) {
            this.writer = PrintWriter(writer)
        }

        fun printLine(array: CharArray) {
            writer.println(array)
        }

        fun close() {
            writer.close()
        }

        fun printLine(i: Int) {
            writer.println(i)
        }

    }

    internal object ArrayUtils {
        fun fill(array: Array<LongArray>, value: Long) {
            for (row in array) {
                Arrays.fill(row, value)
            }
        }

        fun fill(array: Array<Array<LongArray>>, value: Long) {
            for (row in array) {
                fill(row, value)
            }
        }

        fun fill(array: Array<Array<Array<LongArray>>>, value: Long) {
            for (row in array) {
                fill(row, value)
            }
        }

    }
}