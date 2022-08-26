
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
        val solver = HIgraSOtrezkami()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class HIgraSOtrezkami {
        fun solve(testNumber: Int, `in`: InputReader, out: OutputWriter) {
            val n = `in`.readInt()
            val m = `in`.readInt()
            val l = IntArray(n)
            val r = IntArray(n)
            `in`.readIntArrays(l, r)
            val a = IntArray(m)
            val b = IntArray(m)
            `in`.readIntArrays(a, b)

            val first = IntArray(1000000)
            val next = IntArray(m)
            Arrays.fill(first, -1)
            for (i in 0 until m) {
                val delta = b[i] - a[i]
                next[i] = first[delta]
                first[delta] = i
            }
            val aFirst = IntArray(1000000)
            val aNext = IntArray(n)
            Arrays.fill(aFirst, -1)
            for (i in 0 until n) {
                val delta = r[i] - l[i]
                aNext[i] = aFirst[delta]
                aFirst[delta] = i
            }
            val answer = IntArray(n)
            val toCheck = IntArray(2 * m)
            for (z in 0..1) {
                val map = IntHashMap()
                for (i in 0..499999) {
                    var size = 0
                    run {
                        var j = first[2 * i + z]
                        while (j != -1) {
                            map.put(a[j] + i, i)
                            toCheck[size++] = a[j] + i - 1
                            toCheck[size++] = a[j] + i + 1
                            j = next[j]
                        }
                    }
                    run {
                        var j = aFirst[2 * i + z]
                        while (j != -1) {
                            if (map.contains(l[j] + i)) {
                                answer[j] = i - map[l[j] + i]
                            } else {
                                answer[j] = -1
                            }
                            j = aNext[j]
                        }
                    }
                    for (j in 0 until size) {
                        val cur = toCheck[j]
                        if (map.contains(cur - 1) && map.contains(cur + 1)) {
                            val cand = Math.min(map[cur - 1], map[cur + 1])
                            if (map.contains(cur)) {
                                map.put(cur, Math.max(cand, map[cur]))
                            } else {
                                map.put(cur, cand)
                            }
                        }
                    }
                }
            }
            out.printLine(answer)
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

    internal class IntHashMap @JvmOverloads constructor(capacity: Int = 3) {
        private var size: Int = 0
        private var realSize: Int = 0
        private var keys = EMPTY
        private var values = EMPTY
        private var present = EMPTY
        private var step: Int = 0
        private val ratio: Int
        private var lastKey = 0

        init {
            var capacity = capacity
            capacity = Math.max(capacity, 1)
            keys = IntArray(capacity)
            present = IntArray(capacity)
            values = IntArray(capacity)
            ratio = 2
            initStep(capacity)
        }

        private fun initStep(capacity: Int) {
            step = RND.nextInt(capacity - 2) + 1
            while (IntegerUtils.gcd(step, capacity) != 1) {
                step++
            }
        }

        fun put(key: Int, value: Int) {
            ensureCapacity((realSize + 1) * ratio + 2)
            var current = getHash(key)
            while (present[current] != 0) {
                if (present[current] and PRESENT_MASK != 0 && keys[current] == key) {
                    values[current] = value
                    return
                }
                current += step
                if (current >= values.size) {
                    current -= values.size
                }
            }
            while (present[current] and PRESENT_MASK != 0) {
                current += step
                if (current >= keys.size) {
                    current -= keys.size
                }
            }
            if (present[current] == 0) {
                realSize++
            }
            present[current] = PRESENT_MASK
            keys[current] = key
            values[current] = value
            size++
            lastKey = current
        }

        private fun getHash(key: Int): Int {
            var result = key
            for (i in SHIFTS) {
                result = result xor (key shr i)
            }
            result %= keys.size
            if (result < 0) {
                result += keys.size
            }
            return result
        }

        private fun ensureCapacity(capacity: Int) {
            var capacity = capacity
            if (keys.size < capacity) {
                capacity = Math.max(capacity * 2, keys.size)
                rebuild(capacity)
            }
        }

        private fun rebuild(capacity: Int) {
            initStep(capacity)
            val oldKeys = keys
            val oldPresent = present
            val oldValues = values
            keys = IntArray(capacity)
            present = IntArray(capacity)
            values = IntArray(capacity)
            size = 0
            realSize = 0
            for (i in oldKeys.indices) {
                if (oldPresent[i] and PRESENT_MASK == PRESENT_MASK) {
                    put(oldKeys[i], oldValues[i])
                }
            }
        }

        operator fun contains(key: Int): Boolean {
            var current = getHash(key)
            while (present[current] != 0) {
                if (keys[current] == key && present[current] and PRESENT_MASK != 0) {
                    lastKey = current
                    return true
                }
                current += step
                if (current >= keys.size) {
                    current -= keys.size
                }
            }
            return false
        }

        operator fun get(key: Int): Int {
            if (present[lastKey] and PRESENT_MASK != 0 && keys[lastKey] == key) {
                return values[lastKey]
            }
            var current = getHash(key)
            while (present[current] != 0) {
                if (keys[current] == key && present[current] and PRESENT_MASK != 0) {
                    return values[current]
                }
                current += step
                if (current >= keys.size) {
                    current -= keys.size
                }
            }
            throw NoSuchElementException()
        }

        companion object {
            private val EMPTY = IntArray(0)
            private val RND = Random()
            private val SHIFTS = IntArray(4)
            private val PRESENT_MASK = 1

            init {
                for (i in 0..3) {
                    SHIFTS[i] = RND.nextInt(31) + 1
                }
            }
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