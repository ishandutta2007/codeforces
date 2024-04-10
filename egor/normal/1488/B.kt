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
        val solver = TaskB()
        val testCount = `in`.next().toInt()
        for (i in 1..testCount) {
            solver.solve(i, `in`, out)
        }
        out.close()
    }

    internal class TaskB {
        fun solve(testNumber: Int, `in`: InputReader, out: OutputWriter) {
            val n = `in`.readInt()
            val k = `in`.readInt()
            val s = `in`.readCharArray(n)
            var zero = 0
            var bal = 0
            for (c in s) {
                if (c == '(') {
                    bal++
                } else {
                    bal--
                }
                if (bal == 0) {
                    zero++
                }
            }
            out.printLine(Math.min(zero + k, n / 2))
        }
    }

    internal class InputReader(private val stream: InputStream) {
        private val buf = ByteArray(1024)
        private var curChar = 0
        private var numChars = 0
        private val filter: SpaceCharFilter? = null
        fun readCharArray(size: Int): CharArray {
            val array = CharArray(size)
            for (i in 0 until size) {
                array[i] = readCharacter()
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

        fun readCharacter(): Char {
            var c = read()
            while (isSpaceChar(c)) {
                c = read()
            }
            return c.toChar()
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