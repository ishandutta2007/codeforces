
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
        val solver = FDuneIIBattleForArrakis()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class FDuneIIBattleForArrakis {
        fun solve(testNumber: Int, `in`: InputReader, out: OutputWriter) {
            val n = `in`.readInt()
            val m = `in`.readInt()
            val q = `in`.readInt()
            val a = `in`.readIntTable(n, m)

            val rows = LongArray(n)
            val cols = LongArray(m)
            var sum: Long = 0
            for (i in 0 until n) {
                for (j in 0 until m) {
                    rows[i] += a[i][j].toLong()
                    cols[j] += a[i][j].toLong()
                    sum += a[i][j].toLong()
                }
            }
            val res = LongArray(q + 1)
            for (i in 0..q) {
                var fromStart: Long = 0
                var answer: Long = 0
                for (j in 0 until n) {
                    fromStart += rows[j]
                    if (fromStart >= (sum + 1) / 2) {
                        for (k in 0 until j) {
                            answer += rows[k] * (j - k)
                        }
                        for (k in j until n) {
                            answer += rows[k] * (k - j)
                        }
                        break
                    }
                }
                fromStart = 0
                for (j in 0 until m) {
                    fromStart += cols[j]
                    if (fromStart >= (sum + 1) / 2) {
                        for (k in 0 until j) {
                            answer += cols[k] * (j - k)
                        }
                        for (k in j until m) {
                            answer += cols[k] * (k - j)
                        }
                        break
                    }
                }
                res[i] = answer
                if (i == q) {
                    break
                }
                val x = `in`.readInt() - 1
                val y = `in`.readInt() - 1
                val z = `in`.readInt()
                val delta = (z - a[x][y]).toLong()
                a[x][y] = z
                rows[x] += delta
                cols[y] += delta
                sum += delta
            }
            out.printLine(res)
        }

    }

    internal class InputReader(private val stream: InputStream) {
        private val buf = ByteArray(1024)
        private var curChar: Int = 0
        private var numChars: Int = 0
        private val filter: InputReader.SpaceCharFilter? = null

        fun readIntTable(rowCount: Int, columnCount: Int): Array<IntArray> {
            val table = Array<IntArray>(rowCount, { i: Int ->  IntArray(0)})
            for (i in 0 until rowCount) {
                table[i] = readIntArray(columnCount)
            }
            return table
        }

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