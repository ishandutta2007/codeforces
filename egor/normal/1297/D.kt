
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
        val testCount = Integer.parseInt(`in`.next())
        for (i in 1..testCount) {
            solver.solve(i, `in`, out)
        }
        out.close()
    }

    internal class TaskD {
        fun solve(testNumber: Int, `in`: InputReader, out: OutputWriter) {
            val n = `in`.readInt()
            var k = `in`.readInt()
            val a = `in`.readIntArray(n)
            val d = IntArray(n)
            val order = ArrayUtils.order(a)
            ArrayUtils.reverse(order)
            var last = a[order[0]] + 1
            for (i in order) {
                d[i] = Math.min(k, last - a[i] - 1)
                k -= d[i]
                last = a[i] + d[i]
            }
            ArrayUtils.reverse(order)
            var rem = n
            for (i in order) {
                d[i] += k / rem
                k -= k / rem
                rem--
            }
            out.printLine(d)
        }

    }

    internal interface IntReversableCollection : IntCollection

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

        override fun toArray(): IntArray {
            return Arrays.copyOf(data, size)
        }

        companion object {
            private val EMPTY = IntArray(0)
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

    internal class OutputWriter {
        private val writer: PrintWriter

        constructor(outputStream: OutputStream) {
            writer = PrintWriter(BufferedWriter(OutputStreamWriter(outputStream)))
        }

        constructor(writer: Writer) {
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

    }

    internal object Sorter {
        private val INSERTION_THRESHOLD = 16

        fun sort(list: IntList, comparator: IntComparator) {
            quickSort(list, 0, list.size() - 1, Integer.bitCount(Integer.highestOneBit(list.size()) - 1) * 5 shr 1,
                    comparator)
        }

        private fun quickSort(list: IntList, from: Int, to: Int, remaining: Int, comparator: IntComparator) {
            var remaining = remaining
            if (to - from < INSERTION_THRESHOLD) {
                insertionSort(list, from, to, comparator)
                return
            }
            if (remaining == 0) {
                heapSort(list, from, to, comparator)
                return
            }
            remaining--
            val pivotIndex = from + to shr 1
            val pivot = list[pivotIndex]
            list.swap(pivotIndex, to)
            var storeIndex = from
            var equalIndex = to
            run {
                var i = from
                while (i < equalIndex) {
                    val value = comparator.compare(list[i], pivot)
                    if (value < 0) {
                        list.swap(storeIndex++, i)
                    } else if (value == 0) {
                        list.swap(--equalIndex, i--)
                    }
                    i++
                }
            }
            quickSort(list, from, storeIndex - 1, remaining, comparator)
            for (i in equalIndex..to) {
                list.swap(storeIndex++, i)
            }
            quickSort(list, storeIndex, to, remaining, comparator)
        }

        private fun heapSort(list: IntList, from: Int, to: Int, comparator: IntComparator) {
            for (i in to + from - 1 shr 1 downTo from) {
                siftDown(list, i, to, comparator, from)
            }
            for (i in to downTo from + 1) {
                list.swap(from, i)
                siftDown(list, from, i - 1, comparator, from)
            }
        }

        private fun siftDown(list: IntList, start: Int, end: Int, comparator: IntComparator, delta: Int) {
            var start = start
            val value = list[start]
            while (true) {
                var child = (start - delta shl 1) + 1 + delta
                if (child > end) {
                    return
                }
                var childValue = list[child]
                if (child + 1 <= end) {
                    val otherValue = list[child + 1]
                    if (comparator.compare(otherValue, childValue) > 0) {
                        child++
                        childValue = otherValue
                    }
                }
                if (comparator.compare(value, childValue) >= 0) {
                    return
                }
                list.swap(start, child)
                start = child
            }
        }

        private fun insertionSort(list: IntList, from: Int, to: Int, comparator: IntComparator) {
            for (i in from + 1..to) {
                val value = list[i]
                for (j in i - 1 downTo from) {
                    if (comparator.compare(list[j], value) <= 0) {
                        break
                    }
                    list.swap(j, j + 1)
                }
            }
        }

    }

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

    internal object ArrayUtils {
        fun range(from: Int, to: Int): IntArray {
            return Range.range(from, to).toArray()
        }

        fun createOrder(size: Int): IntArray {
            return range(0, size)
        }

        fun sort(array: IntArray, comparator: IntComparator): IntArray {
            return sort(array, 0, array.size, comparator)
        }

        fun sort(array: IntArray, from: Int, to: Int, comparator: IntComparator): IntArray {
            if (from == 0 && to == array.size) {
                IntArr(array).sort(comparator)
            } else {
                IntArr(array).subList(from, to).sort(comparator)
            }
            return array
        }

        fun order(array: IntArray): IntArray {
            return sort(createOrder(array.size), object : IntComparator {
                override fun compare(first: Int, second: Int): Int {
                    if (array[first] < array[second]) {
                        return -1
                    }
                    return if (array[first] > array[second]) {
                        1
                    } else 0
                }
            })
        }

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

    internal interface IntComparator {
        fun compare(first: Int, second: Int): Int

    }

    internal interface IntCollection : IntStream {
        fun size(): Int

        open fun add(value: Int) {
            throw UnsupportedOperationException()
        }

        open fun toArray(): IntArray {
            val size = size()
            val array = IntArray(size)
            var i = 0
            val it = intIterator()
            while (it.isValid) {
                array[i++] = it.value()
                it.advance()
            }
            return array
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

    internal object Range {
        fun range(from: Int, to: Int): IntList {
            val result = IntArray(Math.abs(from - to))
            var current = from
            if (from <= to) {
                for (i in result.indices) {
                    result[i] = current++
                }
            } else {
                for (i in result.indices) {
                    result[i] = current--
                }
            }
            return IntArr(result)
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

        fun sort(comparator: IntComparator): IntList {
            Sorter.sort(this, comparator)
            return this
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

        fun subList(from: Int, to: Int): IntList {
            return object : IntList {
                private val shift: Int
                private val size: Int

                init {
                    if (from < 0 || from > to || to > this@IntList.size()) {
                        throw IndexOutOfBoundsException("from = " + from + ", to = " + to + ", size = " + size())
                    }
                    shift = from
                    size = to - from
                }

                override fun size(): Int {
                    return size
                }

                override fun get(at: Int): Int {
                    if (at < 0 || at >= size) {
                        throw IndexOutOfBoundsException("at = " + at + ", size = " + size())
                    }
                    return this@IntList[at + shift]
                }

                override fun addAt(index: Int, value: Int) {
                    throw UnsupportedOperationException()
                }

                override fun removeAt(index: Int) {
                    throw UnsupportedOperationException()
                }

                override fun set(at: Int, value: Int) {
                    if (at < 0 || at >= size) {
                        throw IndexOutOfBoundsException("at = " + at + ", size = " + size())
                    }
                    this@IntList[at + shift] = value
                }

                fun compute(): IntList {
                    return IntArrayList(this)
                }
            }
        }

    }
}