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
        val solver = FRazbienieDvoichnoiStroki()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class FRazbienieDvoichnoiStroki {
        fun solve(testNumber: Int, `in`: InputReader, out: OutputWriter) {
            val s = `in`.readString()
            val n = s.length
            var next0 = n
            var next1 = n
            var after0 = n
            var after1 = n
            val next = Array(2) { Array(19) { IntArray(n + 1) } }
            next[0][0][n] = n
            next[1][0][n] = n
            for (i in n - 1 downTo 0) {
                if (s[i] == '0') {
                    next0 = after0
                    after0 = i
                } else {
                    next1 = after1
                    after1 = i
                }
                next[0][0][i] = next0
                next[1][0][i] = next1
            }
            for (i in 1..18) {
                for (j in 0..1) {
                    for (k in 0..n) {
                        next[j][i][k] = next[j][i - 1][next[j][i - 1][k]]
                    }
                }
            }
            val ans = IntArray(n)
            for (i in 0 until n) {
                val l = i + 1
                var st = 0
                while (st < n) {
                    ans[i]++
                    var st0 = st
                    var st1 = st
                    for (j in 0..18) {
                        if (l shr j and 1 == 1) {
                            st0 = next[0][j][st0]
                            st1 = next[1][j][st1]
                        }
                    }
                    st = Math.max(st0, st1)
                }
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

        fun readString(): String {
            var c = read()
            while (isSpaceChar(c)) {
                c = read()
            }
            val res = StringBuilder()
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c)
                }
                c = read()
            } while (!isSpaceChar(c))
            return res.toString()
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