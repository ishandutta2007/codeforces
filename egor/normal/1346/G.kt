import java.io.OutputStream
import java.io.IOException
import java.io.InputStream
import java.io.PrintWriter
import java.util.Arrays
import java.io.BufferedWriter
import java.io.Writer
import java.io.OutputStreamWriter
import java.util.InputMismatchException

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
        val solver = GDveIPKameri()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class GDveIPKameri {
        fun solve(testNumber: Int, `in`: InputReader, out: OutputWriter) {
            val k = `in`.readInt()
            val n = `in`.readInt()
            val p = `in`.readIntArray(k)
            val x = `in`.readIntArray(n)

            val qty = IntArray(p[k - 1])
            val threshold = (n + 1) / 2
            val id = IntArray(x[n - 1])
            for (i in p) {
                var j = i
                while (j < id.size) {
                    id[j] = i
                    j += i
                }
            }
            for (i in 0 until k) {
                if (p[i].toLong() * (threshold - 1) >= x[n - 1].toLong()) {
                    break
                }
                Arrays.fill(qty, 0, p[i], 0)
                for (j in x) {
                    qty[j % p[i]]++
                }
                for (j in 0 until p[i]) {
                    if (qty[j] >= threshold) {
                        var first = -1
                        var gcd = 0
                        for (l in 0 until n) {
                            if (x[l] % p[i] != j) {
                                if (first == -1) {
                                    first = x[l]
                                } else {
                                    gcd = IntegerUtils.gcd(gcd, x[l] - first)
                                }
                            }
                        }
                        if (gcd == 0 || id[gcd] != 0) {
                            out.printLine("YES")
                            out.printLine(if (j == 0) p[i] else j, p[i])
                            if (first == -1) {
                                first = 1
                            }
                            if (gcd == 0) {
                                gcd = p[0]
                            } else {
                                gcd = id[gcd]
                            }
                            out.printLine(first, gcd)
                            return
                        }
                    }
                }
            }
            out.printLine("NO")
        }

    }

    internal object IntegerUtils {
        fun gcd(a: Int, b: Int): Int {
            var a = a
            var b = b
            a = Math.abs(a)
            b = Math.abs(b)
            while (b != 0) {
                val temp = a % b
                a = b
                b = temp
            }
            return a
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

        fun print(vararg objects: Any) {
            for (i in objects.indices) {
                if (i != 0) {
                    writer.print(' ')
                }
                writer.print(objects[i])
            }
        }

        fun printLine(vararg objects: Any) {
            print(*objects)
            writer.println()
        }

        fun close() {
            writer.close()
        }

    }

    internal class InputReader(private val stream: InputStream) {
        private val buf = ByteArray(1024)
        private var curChar: Int = 0
        private var numChars: Int = 0
        private val filter: InputReader.SpaceCharFilter? = null

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
}