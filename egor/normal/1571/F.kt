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
        val solver = FKotlinforces()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class FKotlinforces {
        fun solve(testNumber: Int, `in`: InputReader, out: OutputWriter) {
            val n = `in`.readInt()
            var m = `in`.readInt()
            val k = IntArray(n)
            val t = IntArray(n)
            `in`.readIntArrays(k, t)
            val ans = IntArray(n)
            for (i in 0 until n) {
                if (t[i] == 1) {
                    ans[i] = m - k[i] + 1
                    m -= k[i]
                }
            }
            if (m < 0) {
                out.printLine(-1)
                return
            }
            val way = Array((m + 3) / 2) { IntArray((m + 2) / 2) }
            way[0][0] = 1
            var sum = 0
            for (i in 0 until n) {
                if (t[i] == 2) {
                    for (j in 0..sum) {
                        val l = sum - j
                        if (j >= way.size)
                            break
                        if (j < way.size && l < way[j].size && way[j][l] != 0) {
                            if (j + k[i] < way.size) {
                                way[j + k[i]][l] = 1
                            }
                            if (l + k[i] < way[j].size) {
                                way[j][l + k[i]] = -1
                            }
                        }
                    }
                    sum += k[i]
                    if (sum > m) {
                        out.printLine(-1)
                        return
                    }
                }
            }
            var a = -1
            var b = -1
            for (i in 0..sum) {
                val j = sum - i
                if (i < way.size && j < way[i].size && way[i][j] != 0) {
                    a = i
                    b = j
                    break
                }
            }
            if (a == -1) {
                out.printLine(-1)
                return
            }
            for (i in n - 1 downTo 0) {
                if (t[i] == 2) {
                    if (way[a][b] == 1) {
                        a -= k[i]
                        ans[i] = 2 * a + 1
                    } else {
                        b -= k[i]
                        ans[i] = 2 * b + 2
                    }
                }
            }
            out.printLine(ans)
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

        fun printLine(i: Int) {
            writer.println(i)
        }
    }
}