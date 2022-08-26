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
        val solver = DPoiskStrok()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class DPoiskStrok {
        fun solve(testNumber: Int, `in`: InputReader, out: OutputWriter) {
            val n = `in`.readInt()
            val m = `in`.readInt()
            val id: MutableMap<Long, Int> = HashMap()
            for (i in 0 until n) {
                id[SimpleStringHash(`in`.readString()).hash(0)] = i
            }
            val q = `in`.readInt()
            for (i in 0 until q) {
                val answer: MutableSet<Int> = HashSet()
                val s = `in`.readString()
                val base: StringHash = SimpleStringHash(s)
                for (j in 0..m) {
                    val cur: StringHash = CompositeStringHash(SubstringStringHash(base, 0, j),
                            SubstringStringHash(base, j + 1))
                    val ind = id[cur.hash(0)]
                    if (ind != null) {
                        answer.add(ind)
                    }
                }
                out.printLine(answer.size)
            }
        }
    }

    internal class CompositeStringHash(private val first: StringHash, private val second: StringHash) : AbstractStringHash() {
        private fun ensureCapacity(length: Int) {
            var length = length
            if (firstPower.size >= length) {
                return
            }
            length = Math.max(length + 1, firstPower.size shl 1)
            val oldFirst = firstPower
            val oldSecond = secondPower
            firstPower = LongArray(length)
            secondPower = LongArray(length)
            System.arraycopy(oldFirst, 0, firstPower, 0, oldFirst.size)
            System.arraycopy(oldSecond, 0, secondPower, 0, oldSecond.size)
            secondPower[0] = 1
            firstPower[0] = secondPower[0]
            for (i in Math.max(oldFirst.size, 1) until length) {
                firstPower[i] = firstPower[i - 1] * MULTIPLIER % FIRST_MOD
                secondPower[i] = secondPower[i - 1] * MULTIPLIER % SECOND_MOD
            }
        }

        override fun hash(from: Int, to: Int): Long {
            val firstFirst: Long
            val firstSecond: Long
            val secondFirst: Long
            val secondSecond: Long
            if (to <= first.length()) {
                secondFirst = 0
                secondSecond = 0
            } else {
                val value = second.hash(Math.max(0, from - first.length()), to - first.length())
                secondFirst = value ushr 32
                secondSecond = value and (1L shl 32) - 1
            }
            if (from >= first.length()) {
                firstFirst = 0
                firstSecond = 0
            } else {
                val value = first.hash(from, Math.min(to, first.length()))
                firstFirst = value ushr 32
                firstSecond = value and (1L shl 32) - 1
            }
            return ((firstFirst + secondFirst * firstPower[Math.max(0, first.length() - from)]) %
                    FIRST_MOD shl 32) +
                    (firstSecond + secondSecond * secondPower[Math.max(0, first.length() - from)]) %
                    SECOND_MOD
        }

        override fun length(): Int {
            return first.length() + second.length()
        }

        companion object {
            private var firstPower = LongArray(0)
            private var secondPower = LongArray(0)
        }

        init {
            ensureCapacity(first.length() + 1)
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

    internal interface StringHash {
        fun hash(from: Int, to: Int): Long
        fun hash(from: Int): Long
        fun length(): Int
    }

    internal abstract class AbstractStringHash : StringHash {
        companion object {
            var MULTIPLIER: Long = 0
            var FIRST_REVERSE_MULTIPLIER: Long = 0
            var SECOND_REVERSE_MULTIPLIER: Long = 0
            var FIRST_MOD: Long = 0
            var SECOND_MOD: Long = 0

            init {
                val random = Random(System.currentTimeMillis())
                FIRST_MOD = IntegerUtils.nextPrime((1e9 + random.nextInt(1e9.toInt())).toLong())
                SECOND_MOD = IntegerUtils.nextPrime((1e9 + random.nextInt(1e9.toInt())).toLong())
                MULTIPLIER = random.nextInt(1e9.toInt() - 257) + 257.toLong()
                FIRST_REVERSE_MULTIPLIER = IntegerUtils.reverse(MULTIPLIER, FIRST_MOD)
                SECOND_REVERSE_MULTIPLIER = IntegerUtils.reverse(MULTIPLIER, SECOND_MOD)
            }
        }

        override fun hash(from: Int): Long {
            return hash(from, length())
        }
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

        interface SpaceCharFilter {
            fun isSpaceChar(ch: Int): Boolean
        }

        companion object {
            fun isWhitespace(c: Int): Boolean {
                return c == ' '.toInt() || c == '\n'.toInt() || c == '\r'.toInt() || c == '\t'.toInt() || c == -1
            }
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

        fun isPrime(number: Long): Boolean {
            if (number < 2) {
                return false
            }
            var i: Long = 2
            while (i * i <= number) {
                if (number % i == 0L) {
                    return false
                }
                i++
            }
            return true
        }

        fun nextPrime(from: Long): Long {
            var from = from
            if (from <= 2) {
                return 2
            }
            from += 1 - (from and 1)
            while (!isPrime(from)) {
                from += 2
            }
            return from
        }
    }

    internal class SimpleStringHash(string: CharSequence) : AbstractStringHash() {
        private val firstHash: LongArray
        private val secondHash: LongArray
        override fun hash(from: Int, to: Int): Long {
            return ((firstHash[to] - firstHash[from] + FIRST_MOD) * firstReversePower[from] %
                    FIRST_MOD shl 32) +
                    (secondHash[to] - secondHash[from] + SECOND_MOD) * secondReversePower[from] %
                    SECOND_MOD
        }

        override fun length(): Int {
            return firstHash.size - 1
        }

        companion object {
            var firstReversePower = LongArray(0)
            var secondReversePower = LongArray(0)
            fun ensureCapacity(length: Int) {
                var length = length
                if (firstReversePower.size >= length) {
                    return
                }
                length = Math.max(length + 1, firstReversePower.size shl 1)
                val oldFirst = firstReversePower
                val oldSecond = secondReversePower
                firstReversePower = LongArray(length)
                secondReversePower = LongArray(length)
                System.arraycopy(oldFirst, 0, firstReversePower, 0, oldFirst.size)
                System.arraycopy(oldSecond, 0, secondReversePower, 0, oldSecond.size)
                secondReversePower[0] = 1
                firstReversePower[0] = secondReversePower[0]
                for (i in Math.max(oldFirst.size, 1) until length) {
                    firstReversePower[i] = firstReversePower[i - 1] * FIRST_REVERSE_MULTIPLIER %
                            FIRST_MOD
                    secondReversePower[i] = secondReversePower[i - 1] * SECOND_REVERSE_MULTIPLIER %
                            SECOND_MOD
                }
            }
        }

        init {
            val length = string.length
            ensureCapacity(length)
            firstHash = LongArray(length + 1)
            secondHash = LongArray(length + 1)
            var firstPower: Long = 1
            var secondPower: Long = 1
            for (i in 0 until length) {
                firstHash[i + 1] = (firstHash[i] + string[i].toLong() * firstPower) % FIRST_MOD
                secondHash[i + 1] = (secondHash[i] + string[i].toLong() * secondPower) % SECOND_MOD
                firstPower *= MULTIPLIER
                firstPower %= FIRST_MOD
                secondPower *= MULTIPLIER
                secondPower %= SECOND_MOD
            }
        }
    }

    internal class SubstringStringHash @JvmOverloads constructor(private val base: StringHash, private val from: Int, private val to: Int = base.length()) : AbstractStringHash() {
        override fun hash(from: Int, to: Int): Long {
            if (to + this.from > this.to) {
                throw IndexOutOfBoundsException()
            }
            return base.hash(from + this.from, to + this.from)
        }

        override fun length(): Int {
            return to - from
        }

    }
}