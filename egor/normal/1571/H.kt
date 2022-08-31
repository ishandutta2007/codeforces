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
        val solver = HLuchiLazerov()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class HLuchiLazerov {
        fun solve(testNumber: Int, `in`: InputReader, out: OutputWriter) {
            val n = `in`.readInt()
            val a = `in`.readInt()
            val b = `in`.readInt()
            val x = IntArray(n)
            val y = IntArray(n)
            val p = IntArray(n)
            `in`.readIntArrays(x, y, p)
            val mod = 998244353
            val vert = IntArray(a)
            val hor = IntArray(b)
            val upr = LongArray(a + b)
            val downr = LongArray(a + b)
            Arrays.fill(upr, 1)
            Arrays.fill(downr, 1)
            val inv = IntegerUtils.reverse(1000000, mod.toLong())
            for (i in 0 until n) {
                vert[x[i]] = 1
                hor[y[i]] = 1
                downr[x[i] + y[i]] *= 1 - p[i] * inv % mod
                downr[x[i] + y[i]] %= mod.toLong()
                upr[x[i] - y[i] + b] *= 1 - p[i] * inv % mod
                upr[x[i] - y[i] + b] %= mod.toLong()
            }
            var vq = 0
            var hq = 0
            for (i in 0 until a) {
                vq += vert[i]
            }
            for (i in 0 until b) {
                hq += hor[i]
            }
            var answer = (1 + vq) * (1 + hq).toLong()
            for (i in 0 until a + b) {
                if (downr[i] == 1.toLong()) {
                    continue
                }
                val delta = 1 - downr[i]
                answer += delta
                for (j in 0 until a) {
                    if (vert[j] == 1 && j < i && i - j < b) {
                        answer += delta
                    }
                }
                for (j in 0 until b) {
                    if (hor[j] == 1 && j < i && i - j < a && vert[i - j] == 0) {
                        answer += delta
                    }
                }
                for (j in 0 until a + b) {
                    if (upr[j] == 1.toLong()) {
                        continue
                    }
                    val d2 = 1 - upr[j]
                    val xmy = j - b
                    val xx = i + xmy
                    if (xx <= 0 || xx >= 2 * a) {
                        continue
                    }
                    //                xx /= 2;
                    val yy = xx - 2 * xmy
                    if (yy <= 0 || yy >= 2 * b) {
                        continue
                    }
                    if (xx % 2 == 0 && (vert[xx / 2] == 1 || hor[yy / 2] == 1)) {
                        continue
                    }
                    answer += delta * d2 % mod
                }
            }
            for (i in 0 until a + b) {
                if (upr[i] == 1.toLong()) {
                    continue
                }
                val delta = 1 - upr[i]
                answer += delta
                for (j in 0 until a) {
                    if (vert[j] == 1 && j - i + b > 0 && j - i + b < b) {
                        answer += delta
                    }
                }
                for (j in 0 until b) {
                    if (hor[j] == 1 && j + i - b > 0 && j + i - b < a && vert[j + i - b] == 0) {
                        answer += delta
                    }
                }
            }
            answer %= mod.toLong()
            if (answer < 0) {
                answer += mod.toLong()
            }
            out.printLine(answer)
        }
    }

    internal object IntegerUtils {
        private var _x: Long = 0
        private var _y: Long = 0
        fun trueMod(a: Long, b: Long): Long {
            var a = a
            a %= b
            a += b
            a %= b
            return a
        }

        fun reverse(number: Long, modulo: Long): Long {
            extGcd(number, modulo)
            return trueMod(_x, modulo)
        }

        private fun extGcd(a: Long, b: Long): Long {
            if (a == 0L) {
                _x = 0
                _y = 1
                return b
            }
            val d = extGcd(b % a, a)
            val nx = _y - b / a * _x
            _y = _x
            _x = nx
            return d
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
}