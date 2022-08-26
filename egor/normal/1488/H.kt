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
        val solver = TaskH()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class TaskH {
        var n = 0
        var mats: Array<Matrix?> = arrayOfNulls(0)
        fun multiply(c: Matrix?, a: Matrix?, b: Matrix?) {
            for (i in 0..3) {
                for (j in 0..3) {
                    c!!.vals[i * 4 + j] = 0
                    for (k in 0..3) {
                        c.vals[i * 4 + j] += a!!.vals[i * 4 + k] * b!!.vals[k * 4 + j]
                    }
                    c.vals[i * 4 + j] %= MiscUtils.MODF.toLong()
                }
            }
        }

        fun update(root: Int, left: Int, right: Int, pos: Int, mat: Matrix?) {
            if (left + 1 == right) {
                System.arraycopy(mat!!.vals, 0, mats[root]!!.vals, 0, 16)
                return
            }
            val mid = (left + right) / 2
            if (pos < mid) {
                update(2 * root + 1, left, mid, pos, mat)
            } else {
                update(2 * root + 2, mid, right, pos, mat)
            }
            multiply(mats[root], mats[2 * root + 1], mats[2 * root + 2])
        }

        fun update(pos: Int, mat: Matrix?) {
            update(0, 0, n, pos, mat)
        }

        fun init(root: Int, left: Int, right: Int, start: Array<Matrix?>) {
            mats[root] = Matrix()
            if (left + 1 == right) {
                System.arraycopy(start[left]!!.vals, 0, mats[root]!!.vals, 0, 16)
                return
            }
            val mid = (left + right) / 2
            init(2 * root + 1, left, mid, start)
            init(2 * root + 2, mid, right, start)
            multiply(mats[root], mats[2 * root + 1], mats[2 * root + 2])
        }

        fun solve(testNumber: Int, `in`: InputReader, out: OutputWriter) {
            n = `in`.readInt() - 1
            val q = `in`.readInt()
            mats = arrayOfNulls(4 * n)
            val base = Array(2) { arrayOfNulls<Matrix>(2) }
            for (i in 0..1) {
                for (j in 0..1) {
                    base[i][j] = Matrix()
                    for (k in 0..3) {
                        for (l in 0..3) {
                            if (k == l && i == j) {
                                base[i][j]!!.vals[4 * k + l] = 1
                            } else if (i == 0 && k > l) {
                                base[i][j]!!.vals[4 * k + l] = 1
                            } else if (i == 1 && k < l) {
                                base[i][j]!!.vals[4 * k + l] = 1
                            }
                        }
                    }
                }
            }
            val a = IntArray(n + 1)
            for (i in 0 until n) {
                a[i] = `in`.readInt()
            }
            val start = arrayOfNulls<Matrix>(n)
            for (i in 0 until n) {
                start[i] = base[a[i]][a[i + 1]]
            }
            init(0, 0, n, start)
            for (i in 0 until q) {
                val pos = `in`.readInt() - 1
                a[pos] = 1 - a[pos]
                if (pos > 0) {
                    update(pos - 1, base[a[pos - 1]][a[pos]])
                }
                update(pos, base[a[pos]][a[pos + 1]])
                var answer: Long = 0
                for (j in 0..15) {
                    answer += mats[0]!!.vals[j]
                }
                out.printLine(answer % MiscUtils.MODF)
            }
        }

        internal class Matrix {
            var vals = LongArray(16)
        }
    }

    internal object MiscUtils {
        const val MODF = 998244353
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

        fun close() {
            writer.close()
        }

        fun printLine(i: Long) {
            writer.println(i)
        }
    }
}