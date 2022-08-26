
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
        val solver = TaskB()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class TaskB {
        fun solve(testNumber: Int, `in`: InputReader, out: OutputWriter) {
            val n = `in`.readInt()
            val a = `in`.readIntArray(n)

            val result = IntArrayList()
            val set = IntHashSet()
            ArrayUtils.reverse(a)
            for (i in a) {
                if (!set.contains(i)) {
                    set.add(i)
                    result.add(i)
                }
            }
            result.inPlaceReverse()
            out.printLine(result.size())
            out.printLine(result)
        }

    }

    internal interface IntSet : IntCollection

    internal abstract class IntAbstractStream : IntStream {
        override fun toString(): String {
            val builder = StringBuilder()
            var first = true
            val it = intIterator()
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
            if (o !is IntStream) {
                return false
            }
            val c = o as IntStream?
            val it = intIterator()
            val jt = c!!.intIterator()
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
            val it = intIterator()
            while (it.isValid) {
                result *= 31
                result += it.value()
                it.advance()
            }
            return result
        }

    }

    internal interface IntIterator {

        val isValid: Boolean
        @Throws(NoSuchElementException::class)
        fun value(): Int

        fun advance(): Boolean

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

    internal class IntArr(private val data: IntArray) : IntAbstractStream(), IntList {

        override fun size(): Int {
            return data.size
        }

        override operator fun get(at: Int): Int {
            return data[at]
        }

        override fun addAt(index: Int, value: Int) {
            throw UnsupportedOperationException()
        }

        override fun removeAt(index: Int) {
            throw UnsupportedOperationException()
        }

        override operator fun set(index: Int, value: Int) {
            data[index] = value
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

        fun printLine(i: Int) {
            writer.println(i)
        }

    }

    internal object ArrayUtils {
        fun reverse(array: IntArray) {
            IntArr(array).inPlaceReverse()
        }

    }

    internal interface IntStream : Iterable<Int>, Comparable<IntStream> {
        fun intIterator(): IntIterator

        override fun iterator(): Iterator<Int> {
            return object : Iterator<Int> {
                private val it = intIterator()

                override fun hasNext(): Boolean {
                    return it.isValid
                }

                override fun next(): Int {
                    val result = it.value()
                    it.advance()
                    return result
                }
            }
        }

        override fun compareTo(c: IntStream): Int {
            val it = intIterator()
            val jt = c.intIterator()
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

    }

    internal class IntHashSet @JvmOverloads constructor(capacity: Int = 3) : IntAbstractStream(), IntSet {
        private var size: Int = 0
        private var realSize: Int = 0
        private var values = EMPTY_INT
        private var present = EMPTY_BYTE
        private var step: Int = 0
        private val ratio: Int

        init {
            var capacity = capacity
            capacity = Math.max(capacity, 3)
            values = IntArray(capacity)
            present = IntArray(capacity)
            ratio = 2
            initStep(capacity)
        }

        constructor(c: IntCollection) : this(c.size()) {
            addAll(c)
        }

        constructor(arr: IntArray) : this(IntArr(arr)) {}

        private fun initStep(capacity: Int) {
            step = RND.nextInt(capacity - 2) + 1
            while (IntegerUtils.gcd(step, capacity) != 1) {
                step++
            }
        }

        override fun intIterator(): IntIterator {
            return object : IntIterator {
                private var position = if (size == 0) values.size else -1

                override val isValid: Boolean
                    get() = position < values.size

                @Throws(NoSuchElementException::class)
                override fun value(): Int {
                    if (position == -1) {
                        advance()
                    }
                    if (position >= values.size) {
                        throw NoSuchElementException()
                    }
                    if (present[position] and PRESENT_MASK == 0) {
                        throw IllegalStateException()
                    }
                    return values[position]
                }

                @Throws(NoSuchElementException::class)
                override fun advance(): Boolean {
                    if (position >= values.size) {
                        throw NoSuchElementException()
                    }
                    position++
                    while (position < values.size && present[position] and PRESENT_MASK == 0) {
                        position++
                    }
                    return isValid
                }

                fun remove() {
                    if (present[position] and PRESENT_MASK == 0) {
                        throw IllegalStateException()
                    }
                    present[position] = REMOVED_MASK
                }
            }
        }

        override fun size(): Int {
            return size
        }

        override fun add(value: Int) {
            ensureCapacity((realSize + 1) * ratio + 2)
            var current = getHash(value)
            while (present[current] != 0) {
                if (present[current] and PRESENT_MASK != 0 && values[current] == value) {
                    return
                }
                current += step
                if (current >= values.size) {
                    current -= values.size
                }
            }
            while (present[current] and PRESENT_MASK != 0) {
                current += step
                if (current >= values.size) {
                    current -= values.size
                }
            }
            if (present[current] == 0) {
                realSize++
            }
            present[current] = PRESENT_MASK
            values[current] = value
            size++
        }

        private fun getHash(value: Int): Int {
            val hash = IntHash.hash(value)
            var result = hash
            for (i in SHIFTS) {
                result = result xor (hash shr i)
            }
            result %= values.size
            if (result < 0) {
                result += values.size
            }
            return result
        }

        private fun ensureCapacity(capacity: Int) {
            var capacity = capacity
            if (values.size < capacity) {
                capacity = Math.max(capacity * 2, values.size)
                rebuild(capacity)
            }
        }

        private fun rebuild(capacity: Int) {
            initStep(capacity)
            val oldValues = values
            val oldPresent = present
            values = IntArray(capacity)
            present = IntArray(capacity)
            size = 0
            realSize = 0
            for (i in oldValues.indices) {
                if (oldPresent[i] and PRESENT_MASK == PRESENT_MASK) {
                    add(oldValues[i])
                }
            }
        }

        operator fun contains(value: Int): Boolean {
            var current = getHash(value)
            while (present[current] != 0) {
                if (values[current] == value && present[current] and PRESENT_MASK != 0) {
                    return true
                }
                current += step
                if (current >= values.size) {
                    current -= values.size
                }
            }
            return false
        }

        companion object {
            private val RND = Random()
            private val SHIFTS = IntArray(4)
            private val PRESENT_MASK = 1
            private val REMOVED_MASK = 2
            private val EMPTY_INT = IntArray(0)
            private val EMPTY_BYTE = IntArray(0)

            init {
                for (i in 0..3) {
                    SHIFTS[i] = RND.nextInt(31) + 1
                }
            }
        }

    }

    internal interface IntCollection : IntStream {
        fun size(): Int

        open fun add(value: Int) {
            throw UnsupportedOperationException()
        }

        fun addAll(values: IntStream): IntCollection {
            val it = values.intIterator()
            while (it.isValid) {
                add(it.value())
                it.advance()
            }
            return this
        }

    }

    internal class IntArrayList : IntAbstractStream, IntList {
        private var size: Int = 0
        private var data = EMPTY

        @JvmOverloads
        constructor(capacity: Int = 3) {
            data = IntArray(capacity)
        }

        constructor(c: IntCollection) : this(c.size()) {
            addAll(c)
        }

        constructor(c: IntStream) : this() {
            if (c is IntCollection) {
                ensureCapacity(c.size())
            }
            addAll(c)
        }

        constructor(c: IntArrayList) {
            size = c.size()
            data = c.data.clone()
        }

        constructor(arr: IntArray) {
            size = arr.size
            data = arr.clone()
        }

        override fun size(): Int {
            return size
        }

        override operator fun get(at: Int): Int {
            if (at >= size) {
                throw IndexOutOfBoundsException("at = $at, size = $size")
            }
            return data[at]
        }

        private fun ensureCapacity(capacity: Int) {
            var capacity = capacity
            if (data.size >= capacity) {
                return
            }
            capacity = Math.max(2 * data.size, capacity)
            data = Arrays.copyOf(data, capacity)
        }

        override fun addAt(index: Int, value: Int) {
            ensureCapacity(size + 1)
            if (index > size || index < 0) {
                throw IndexOutOfBoundsException("at = $index, size = $size")
            }
            if (index != size) {
                System.arraycopy(data, index, data, index + 1, size - index)
            }
            data[index] = value
            size++
        }

        override fun removeAt(index: Int) {
            if (index >= size || index < 0) {
                throw IndexOutOfBoundsException("at = $index, size = $size")
            }
            if (index != size - 1) {
                System.arraycopy(data, index + 1, data, index, size - index - 1)
            }
            size--
        }

        override operator fun set(index: Int, value: Int) {
            if (index >= size) {
                throw IndexOutOfBoundsException("at = $index, size = $size")
            }
            data[index] = value
        }

        companion object {
            private val EMPTY = IntArray(0)
        }

    }

    internal interface IntReversableCollection : IntCollection

    internal object IntHash {

        fun hash(c: Int): Int {
            return c
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

    internal interface IntList : IntReversableCollection {
        operator fun get(index: Int): Int

        operator fun set(index: Int, value: Int)

        fun addAt(index: Int, value: Int)

        fun removeAt(index: Int)

        fun swap(first: Int, second: Int) {
            if (first == second) {
                return
            }
            val temp = get(first)
            set(first, get(second))
            set(second, temp)
        }

        override fun intIterator(): IntIterator {
            return object : IntIterator {
                private var at: Int = 0
                private var removed: Boolean = false

                override val isValid: Boolean
                    get() = !removed && at < size()

                override fun value(): Int {
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

        override fun add(value: Int) {
            addAt(size(), value)
        }

        fun inPlaceReverse() {
            var i = 0
            var j = size() - 1
            while (i < j) {
                swap(i, j)
                i++
                j--
            }
        }

    }
}