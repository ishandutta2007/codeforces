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
        val solver = EUkomplektovanieShakhmatnoiKomandi()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class EUkomplektovanieShakhmatnoiKomandi {
        fun solve(testNumber: Int, `in`: InputReader, out: OutputWriter) {
            val n = `in`.readInt()
            val a = `in`.readIntArray(n)
            val b = `in`.readIntArray(n + 1)
            Arrays.sort(a)
            Arrays.sort(b)
            val start = IntArray(n + 1)
            start[0] = Int.MIN_VALUE
            for (i in 0 until n) {
                start[i + 1] = Math.max(start[i], b[i] - a[i])
            }
            val end = IntArray(n + 1)
            end[n] = Int.MIN_VALUE
            for (i in n - 1 downTo 0) {
                end[i] = Math.max(end[i + 1], b[i + 1] - a[i])
            }
            val m = `in`.readInt()
            val c = `in`.readIntArray(m)
            val ans = IntArray(m)
            for (i in 0 until m) {
                var p = Arrays.binarySearch(a, c[i])
                if (p < 0) {
                    p = -p - 1
                }
                ans[i] = Math.max(b[p] - c[i], Math.max(start[p], end[p]))
            }
            out.printLine(ans)
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

        fun print(array: IntArray) {
            for (i in array.indices) {
                if (i != 0) {
                    writer.print(' ')
                }
                writer.print(array[i])
            }
        }

        fun printLine(array: IntArray) {
            print(array)
            writer.println()
        }

        fun close() {
            writer.close()
        }
    }

    internal class InputReader(private val stream: InputStream) {
        private val buf = ByteArray(1024)
        private var curChar = 0
        private var numChars = 0
        private val filter: SpaceCharFilter? = null
        fun readIntArray(size: Int): IntArray {
            val array = IntArray(size)
            for (i in 0 until size) {
                array[i] = readInt()
            }
            return array
        }

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
}