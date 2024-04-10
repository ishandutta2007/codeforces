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
        val solver = DLotereya()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class DLotereya {
        fun solve(testNumber: Int, `in`: InputReader, out: OutputWriter) {
            val n = `in`.readInt()
            val m = `in`.readInt()
            val f = IntArray(m)
            val l = IntArray(m)
            `in`.readIntArrays(f, l)
            MiscUtils.decreaseByOne(f, l)
            val nf = IntArray(n)
            val nl = IntArray(n)
            val q = Array(n) { IntArray(n) }
            for (i in 0 until m) {
                nf[f[i]]++
                nl[l[i]]++
                q[f[i]][l[i]]++
            }
            var answer = 0
            for (i in 0 until n) {
                for (j in 0 until n) {
                    if (i == j) {
                        continue
                    }
                    if (i != f[0]) {
                        answer = if (j != l[0]) {
                            Math.max(answer, nf[i] + nl[j] - q[i][j])
                        } else {
                            Math.max(answer, q[i][j])
                        }
                    } else if (j != l[0]) {
                        answer = Math.max(answer, q[i][j])
                    }
                }
            }
            out.printLine(answer + 1)
        }
    }

    internal class InputReader(private val stream: InputStream) {
        private val buf = ByteArray(1024)
        private var curChar = 0
        private var numChars = 0
        private val filter: SpaceCharFilter? = null
        fun readIntArrays(vararg arrays: IntArray) {
            for (i in 0 until arrays[0].size) {
                for (j in arrays.indices) {
                    arrays[j][i] = readInt()
                }
            }
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

    internal object MiscUtils {
        fun decreaseByOne(vararg arrays: IntArray) {
            for (array in arrays) {
                for (i in array.indices) {
                    array[i]--
                }
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

        fun close() {
            writer.close()
        }

        fun printLine(i: Int) {
            writer.println(i)
        }
    }
}