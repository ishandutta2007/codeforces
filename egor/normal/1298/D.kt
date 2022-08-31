
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
        val solver = TaskD()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class TaskD {
        fun solve(testNumber: Int, `in`: InputReader, out: OutputWriter) {
            val n = `in`.readInt()
            val w = `in`.readLong()
            val a = `in`.readIntArray(n)
            val s = ArrayUtils.partialSums(a)
            val delta = ArrayUtils.maxElement(s) - ArrayUtils.minElement(s)
            if (delta > w) {
                out.printLine(0)
            } else {
                out.printLine(w - delta + 1)
            }
        }

    }

    internal interface LongList : LongReversableCollection {
        operator fun get(index: Int): Long

        fun removeAt(index: Int)

        override fun longIterator(): LongIterator {
            return object : LongIterator {
                private var at: Int = 0
                private var removed: Boolean = false

                override val isValid: Boolean
                    get() = !removed && at < size()

                override fun value(): Long {
                    if (removed) {
                        throw IllegalStateException()
                    }
                    return get(at)
                }

                override fun advance(): Boolean {
                    at++
                    removed = false
                    return isValid
                }

                fun remove() {
                    removeAt(at)
                    at--
                    removed = true
                }
            }
        }

    }

    internal abstract class LongAbstractStream : LongStream {
        override fun toString(): String {
            val builder = StringBuilder()
            var first = true
            val it = longIterator()
            while (it.isValid) {
                if (first) {
                    first = false
                } else {
                    builder.append(' ')
                }
                builder.append(it.value())
                it.advance()
            }
            return builder.toString()
        }

        override fun equals(o: Any?): Boolean {
            if (o !is LongStream) {
                return false
            }
            val c = o as LongStream?
            val it = longIterator()
            val jt = c!!.longIterator()
            while (it.isValid && jt.isValid) {
                if (it.value() != jt.value()) {
                    return false
                }
                it.advance()
                jt.advance()
            }
            return !it.isValid && !jt.isValid
        }

        override fun hashCode(): Int {
            var result = 0
            val it = longIterator()
            while (it.isValid) {
                result *= 31
                result += it.value().toInt()
                it.advance()
            }
            return result
        }

    }

    internal interface LongIterator {

        val isValid: Boolean
        @Throws(NoSuchElementException::class)
        fun value(): Long

        fun advance(): Boolean

    }

    internal interface LongReversableCollection : LongCollection

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

        fun readLong(): Long {
            var c = read()
            while (isSpaceChar(c)) {
                c = read()
            }
            var sgn = 1
            if (c == '-'.toInt()) {
                sgn = -1
                c = read()
            }
            var res: Long = 0
            do {
                if (c < '0'.toInt() || c > '9'.toInt()) {
                    throw InputMismatchException()
                }
                res *= 10
                res += (c - '0'.toInt()).toLong()
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

        fun close() {
            writer.close()
        }

        fun printLine(i: Long) {
            writer.println(i)
        }

        fun printLine(i: Int) {
            writer.println(i)
        }

    }

    internal class LongArr(private val data: LongArray) : LongAbstractStream(), LongList {

        override fun size(): Int {
            return data.size
        }

        override fun get(at: Int): Long {
            return data[at]
        }

        override fun removeAt(index: Int) {
            throw UnsupportedOperationException()
        }

    }

    internal object ArrayUtils {
        fun partialSums(array: IntArray): LongArray {
            val result = LongArray(array.size + 1)
            for (i in array.indices) {
                result[i + 1] = result[i] + array[i]
            }
            return result
        }

        fun minElement(array: LongArray): Long {
            return LongArr(array).min()
        }

        fun maxElement(array: LongArray): Long {
            return LongArr(array).max()
        }

    }

    internal interface LongStream : Iterable<Long>, Comparable<LongStream> {
        fun longIterator(): LongIterator

        override fun iterator(): Iterator<Long> {
            return object : Iterator<Long> {
                private val it = longIterator()

                override fun hasNext(): Boolean {
                    return it.isValid
                }

                override fun next(): Long {
                    val result = it.value()
                    it.advance()
                    return result
                }
            }
        }

        override fun compareTo(c: LongStream): Int {
            val it = longIterator()
            val jt = c.longIterator()
            while (it.isValid && jt.isValid) {
                val i = it.value()
                val j = jt.value()
                if (i < j) {
                    return -1
                } else if (i > j) {
                    return 1
                }
                it.advance()
                jt.advance()
            }
            if (it.isValid) {
                return 1
            }
            return if (jt.isValid) {
                -1
            } else 0
        }

        fun min(): Long {
            var result = java.lang.Long.MAX_VALUE
            val it = longIterator()
            while (it.isValid) {
                val current = it.value()
                if (current < result) {
                    result = current
                }
                it.advance()
            }
            return result
        }

        fun max(): Long {
            var result = java.lang.Long.MIN_VALUE
            val it = longIterator()
            while (it.isValid) {
                val current = it.value()
                if (current > result) {
                    result = current
                }
                it.advance()
            }
            return result
        }

    }

    internal interface LongCollection : LongStream {
        fun size(): Int

    }
}