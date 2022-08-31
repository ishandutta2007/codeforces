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
        val solver = TaskF()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class TaskF {
        fun solve(testNumber: Int, `in`: InputReader, out: OutputWriter) {
            val n = `in`.readInt()
            val c = `in`.readIntArray(n)
            val q = `in`.readInt()
            val l = IntArray(q)
            val r = IntArray(q)
            `in`.readIntArrays(l, r)
            MiscUtils.decreaseByOne(l)
            val order = arrayOfNulls<Int>(q)
            for (i in 0 until q) {
                order[i] = i
            }
            Arrays.sort(order, {x: Int?, y: Int? -> r[x!!] - r[y!!]})
            val tree = FenwickTree(n)
            val parts: MutableList<Part> = ArrayList()
            var at = 0
            val answer = LongArray(q)
            for (i in order) {
                while (at < r[i!!]) {
                    val part = Part(c[at], 1, at)
                    while (!parts.isEmpty()) {
                        val cur = parts[parts.size - 1]
                        if (cur.price > part.price) {
                            break
                        }
                        part.len += cur.len
                        part.pos = cur.pos
                        parts.removeAt(parts.size - 1)
                    }
                    tree.add(parts.size, part.price.toLong() * part.len - tree[parts.size, parts.size])
                    parts.add(part)
                    at++
                }
                var left = 0
                var right = parts.size - 1
                while (left < right) {
                    val mid = (left + right + 1) / 2
                    if (parts[mid].pos > l[i]) {
                        right = mid - 1
                    } else {
                        left = mid
                    }
                }
                answer[i] = tree[left, parts.size - 1] - parts[left].price.toLong() * (l[i] - parts[left].pos)
            }
            out.printLine(answer)
        }

        internal class Part(var price: Int, var len: Int, var pos: Int)
    }

    internal class OutputWriter {
        private val writer: PrintWriter

        constructor(outputStream: OutputStream?) {
            writer = PrintWriter(BufferedWriter(OutputStreamWriter(outputStream)))
        }

        constructor(writer: Writer?) {
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

    internal object MiscUtils {
        fun decreaseByOne(vararg arrays: IntArray) {
            for (array in arrays) {
                for (i in array.indices) {
                    array[i]--
                }
            }
        }
    }

    internal class FenwickTree(size: Int) {
        private val value: LongArray
        operator fun get(from: Int, to: Int): Long {
            return if (from > to) {
                0
            } else get(to) - get(from - 1)
        }

        private operator fun get(to: Int): Long {
            var to = to
            to = Math.min(to, value.size - 1)
            var result: Long = 0
            while (to >= 0) {
                result += value[to]
                to = (to and to + 1) - 1
            }
            return result
        }

        fun add(at: Int, value: Long) {
            var at = at
            while (at < this.value.size) {
                this.value[at] += value
                at = at or at + 1
            }
        }

        init {
            value = LongArray(size)
        }
    }
}