
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
        val solver = DPostroeniePodzemelya()
        val testCount = Integer.parseInt(`in`.next())
        for (i in 1..testCount) {
            solver.solve(i, `in`, out)
        }
        out.close()
    }

    internal class DPostroeniePodzemelya {
        fun solve(testNumber: Int, `in`: InputReader, out: OutputWriter) {
            val n = `in`.readInt()
            val m = `in`.readInt()
            val u = IntArray(m)
            val v = IntArray(m)
            val w = IntArray(m)
            `in`.readIntArrays(u, v, w)
            MiscUtils.decreaseByOne(u, v)

            val a = IntArray(n)
            for (i in 0 until m) {
                a[u[i]] = Math.max(a[u[i]], w[i])
                a[v[i]] = Math.max(a[v[i]], w[i])
            }
            for (i in 0 until m) {
                if (Math.min(a[u[i]], a[v[i]]) != w[i]) {
                    out.printLine("NO")
                    return
                }
            }
            out.printLine("YES")
            out.printLine(a)
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

        operator fun next(): String {
            return readString()
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