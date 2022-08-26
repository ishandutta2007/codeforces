/**
 * @author egor@egork.net
 */
import java.io.*
import java.math.BigInteger
import java.util.*

val inputFile : String? = null
val outputFile : String? = null
val inputType : Int = 0
val tests = arrayOf(
        "  hello ,i AM veRy GooD.Boris", "Hello, i am very good. Boris",
        "       a. b,   C  .   ", "A. B, c."
)

fun solve(inp: InputReader, out: OutputWriter, testNumber: Int) {
    var s = inp.readLine().toCharArray()
    var space = true
    var dot = true
    var answer = StringBuilder()
    for (c in s) {
        if (c == ' ') {
            space = true
        } else if (c == '.') {
            space = true
            dot = true
            answer.append('.')
        } else if (c == ',') {
            space = true
            answer.append(',')
        } else {
            if (space) {
                answer.append(' ')
                if (dot) {
                    answer.append(c.toUpperCase())
                } else {
                    answer.append(c.toLowerCase())
                }
                space = false
                dot = false
            } else {
                answer.append(c.toLowerCase())
            }
        }
    }
    out.printLine(answer.toString().trim())
}

fun read(inp: InputReader): Array<Int> {
    var n = inp.readInt()
    return Array(n, { inp.readInt() })
}

data class Student(val name: String, val height: Int)

fun check(input: String, answer: String, output: String): String {
    var expected = InputReader(StringBufferInputStream(answer))
    var actual = InputReader(StringBufferInputStream(output))

    while (true) {
        if (expected.isExhausted()) {
            if (actual.isExhausted())
                return "OK"
            return "PE, excessive tokens"
        }
        if (actual.isExhausted())
            return "PE, not enough tokens"
        val expectedToken = expected.readString()
        val actualToken = actual.readString()
        if (!expectedToken.equals(actualToken))
            return "WA, " + expectedToken + " != " + actualToken
    }
}

fun main(args: Array<String>) {
    Locale.setDefault(Locale.US)
    if (args.size != 0 && "Test".equals(args[0])) {
        test()
    } else {
        var inp: InputReader
        if (inputFile == null)
            inp = InputReader(System.`in`)
        else
            inp = InputReader(FileInputStream(inputFile))
        var out: OutputWriter
        if (outputFile == null)
            out = OutputWriter(PrintWriter(System.out))
        else
            out = OutputWriter.init(FileOutputStream(outputFile))
        run(inp, out)
    }
}

fun test() {
    Thread.sleep(100)
    var i = 0
    var maxTime: Long = 0
    var ok = -1
    while (i < tests.size) {
        var input = tests[i]
        var answer = tests[i + 1]
        i += 2
        var testNumber = i / 2
        var inp = InputReader(StringBufferInputStream(input))
        var sw = StringWriter()
        var out = OutputWriter(PrintWriter(sw))
        println("Test #" + testNumber)
        println("Input:")
        println(input)
        println()
        println("Answer:")
        println(answer)
        println()
        println("Output:")
        var time = System.currentTimeMillis()
        var verdict: String
        try {
            run(inp, out)
            time = System.currentTimeMillis() - time
            var output = sw.toString()
            println(output)
            verdict = check(input, answer, output)
        } catch (e: Throwable) {
            verdict = "Runtime Error (" + e.javaClass.getSimpleName() + ")"
            println(e.message)
            e.printStackTrace()
        }
        println("Verdict = " + verdict)
        if (!verdict.equals("OK"))
            ok = testNumber
        println(java.lang.String.format("Time = %.3f\n", time / 1000.0))
        maxTime = Math.max(maxTime, time)
        println("----------------------------------------------------------")
    }
    if (ok == -1)
        println("All test passed")
    else
        println("First failed test = " + ok)
    println(java.lang.String.format("Maximal time = %.3f\n", maxTime / 1000.0))
}

fun run(inp: InputReader, out: OutputWriter) {
    if (inputType == 0)
        solve(inp, out, 1)
    else if (inputType == 1) {
        var testCount = inp.readInt()
        for (i in 1..testCount) {
            solve(inp, out, i)
        }
    } else if (inputType == 2) {
        try {
            var test = 1
            while (true) {
                solve(inp, out, test++)
            }
        } catch (e: UnknownError) {
        }
    }
    out.close()
}

open class InputReader(val stream: InputStream) {
    private var finished: Boolean = false
    private var buf: ByteArray = ByteArray(1024)
    private var curChar: Int = 0
    private var numChars: Int = 0
    private var filter: SpaceCharFilter? = null

    public open fun read(): Int {
        if (numChars == -1)
            throw InputMismatchException()

        if (curChar >= numChars)
        {
            curChar = 0
            try
            {
                numChars = stream.read(buf)
            }
            catch (e: IOException) {
                throw InputMismatchException()
            }

            if (numChars <= 0)
                return -1

        }

        return buf[curChar++].toInt()
    }
    public open fun peek(): Int {
        if (numChars == -1)
            return -1

        if (curChar >= numChars)
        {
            curChar = 0
            try
            {
                numChars = stream.read(buf)
            }
            catch (e: IOException) {
                return -1
            }

            if (numChars <= 0)
                return -1

        }

        return buf[curChar].toInt()
    }
    public open fun readInt(): Int {
        var c: Int = read()
        while (isSpaceChar(c))
            c = read()
        var sgn: Int = 1
        if (c == '-'.toInt())
        {
            sgn = -1
            c = read()
        }

        var res: Int = 0
        do
        {
            if (c.toInt() < '0'.toInt() || c.toInt() > '9'.toInt())
                throw InputMismatchException()

            res *= 10
            res += c.toInt() - '0'.toInt()
            c = read()
        }
        while (!isSpaceChar(c))
        return res * sgn
    }
    public open fun readLong(): Long {
        var c: Int = read()
        while (isSpaceChar(c))
            c = read()
        var sgn: Int = 1
        if (c == '-'.toInt())
        {
            sgn = -1
            c = read()
        }

        var res: Long = 0
        do
        {
            if (c.toInt() < '0'.toInt() || c.toInt() > '9'.toInt())
                throw InputMismatchException()

            res *= 10
            res += c.toInt() - '0'.toInt()
            c = read()
        }
        while (!isSpaceChar(c))
        return res * sgn
    }
    public open fun readString(): String {
        var c: Int = read()
        while (isSpaceChar(c))
            c = read()
        var res: StringBuilder = StringBuilder()
        do
        {
            res.appendCodePoint(c)
            c = read()
        }
        while (!isSpaceChar(c))
        return res.toString()
    }
    public open fun isSpaceChar(c: Int): Boolean {
        if (filter != null)
            return filter?.isSpaceChar(c)!!

        return isWhitespace(c)
    }
    private fun readLine0(): String {
        var buf: StringBuilder = StringBuilder()
        var c: Int = read()
        while (c != '\n'.toInt() && c != -1)
        {
            if (c != '\r'.toInt())
                buf.appendCodePoint(c)

            c = read()
        }
        return buf.toString()
    }
    public open fun readLine(): String {
        var s: String = readLine0()
        while ((s.trim().length) == 0)
            s = readLine0()
        return s
    }
    public open fun readLine(ignoreEmptyLines: Boolean): String {
        if (ignoreEmptyLines)
            return readLine()
        else
            return readLine0()
    }
    public open fun readBigInteger(): BigInteger {
        try
        {
            return BigInteger(readString())
        }
        catch (e: NumberFormatException) {
            throw InputMismatchException()
        }

    }
    public open fun readCharacter(): Char {
        var c: Int = read()
        while (isSpaceChar(c))
            c = read()
        return c.toChar()
    }
    public open fun readDouble(): Double {
        var c: Int = read()
        while (isSpaceChar(c))
            c = read()
        var sgn: Int = 1
        if (c == '-'.toInt())
        {
            sgn = -1
            c = read()
        }

        var res: Double = 0.0
        while (!isSpaceChar(c) && c != '.'.toInt())
        {
            if (c == 'e'.toInt() || c == 'E'.toInt())
                return res * Math.pow((10).toDouble(), (readInt()).toDouble())

            if (c.toInt() < '0'.toInt() || c.toInt() > '9'.toInt())
                throw InputMismatchException()

            res *= 10
            res += c.toInt() - '0'.toInt()
            c = read()
        }
        if (c == '.'.toInt())
        {
            c = read()
            var m: Double = 1.0
            while (!isSpaceChar(c))
            {
                if (c == 'e'.toInt() || c == 'E'.toInt())
                    return res * Math.pow((10).toDouble(), (readInt()).toDouble())

                if (c.toInt() < '0'.toInt() || c.toInt() > '9'.toInt())
                    throw InputMismatchException()

                m /= 10
                res += (c.toInt() - '0'.toInt()) * m
                c = read()
            }
        }

        return res * sgn
    }
    public open fun isExhausted(): Boolean {
        var value: Int
        while (true) {
            value = peek()
            if (!isSpaceChar(value) || value == -1)
                break
            read()
        }
        return value == -1
    }
    public open fun next(): String {
        return readString()
    }
    companion object {
        public open fun isWhitespace(c: Int): Boolean {
            return c == ' '.toInt() || c == '\n'.toInt() || c == '\r'.toInt() || c == '\t'.toInt() || c == -1
        }
        public interface SpaceCharFilter {
            public open fun isSpaceChar(ch: Int): Boolean
        }
    }
}

public open class OutputWriter(val writer: PrintWriter) {
    public open fun print(array: CharArray): Unit {
        writer.print(array)
    }
    public open fun print(vararg objects: Any): Unit {
        for (i in 0..objects.size - 1) {
            if (i != 0)
                writer.print(' ')

            writer.print(objects[i])
        }
    }
    public open fun print(array: IntArray): Unit {
        for (i in 0..array.size - 1) {
            if (i != 0)
                writer.print(' ')

            writer.print(array[i])
        }
    }
    public open fun print(array: LongArray): Unit {
        for (i in 0..array.size - 1) {
            if (i != 0)
                writer.print(' ')

            writer.print(array[i])
        }
    }
    public open fun printLine(array: IntArray): Unit {
        print(array)
        writer.println()
    }
    public open fun printLine(array: LongArray): Unit {
        print(array)
        writer.println()
    }
    public open fun printLine(): Unit {
        writer.println()
    }
    public open fun printLine(vararg objects: Any): Unit {
        print(*objects)
        writer.println()
    }
    public open fun print(i: Char): Unit {
        writer.print(i)
    }
    public open fun printLine(i: Char): Unit {
        writer.println(i)
    }
    public open fun printLine(array: CharArray): Unit {
        writer.println(array)
    }
    public open fun printFormat(format: String, vararg objects: Any): Unit {
        writer.printf(format, objects)
    }
    public open fun close(): Unit {
        writer.close()
    }
    public open fun flush(): Unit {
        writer.flush()
    }
    public open fun print(i: Long): Unit {
        writer.print(i)
    }
    public open fun printLine(i: Long): Unit {
        writer.println(i)
    }
    public open fun print(i: Int): Unit {
        writer.print(i)
    }
    public open fun printLine(i: Int): Unit {
        writer.println(i)
    }
    companion object {
        public open fun init(outputStream: OutputStream): OutputWriter {
            val __1 = OutputWriter(PrintWriter(BufferedWriter(OutputStreamWriter(outputStream))))
            return __1
        }
        public open fun init(writer: Writer): OutputWriter {
            val __1 = OutputWriter(PrintWriter(writer))
            return __1
        }
    }
}

public open class IntegerUtils() {
    companion object {
        public open fun gcd(_a: Long, _b: Long): Long {
            var a = _a
            var b = _b
            a = Math.abs(a)
            b = Math.abs(b)
            while (b != 0.toLong())
            {
                var temp: Long = a % b
                a = b
                b = temp
            }
            return a
        }
        public open fun gcd(_a: Int, _b: Int): Int {
            var a = _a
            var b = _b
            a = Math.abs(a)
            b = Math.abs(b)
            while (b != 0)
            {
                var temp: Int = a % b
                a = b
                b = temp
            }
            return a
        }
        public open fun generatePrimes(upTo: Int): IntArray {
            var isPrime: BooleanArray = generatePrimalityTable(upTo)
            var primes: MutableList<Int>? = ArrayList()
            for (i in 0..upTo - 1) {
                if (isPrime[i])
                    primes?.add(i)

            }
            return primes?.toIntArray()!!
        }
        public open fun generatePrimalityTable(upTo: Int): BooleanArray {
            var isPrime: BooleanArray = BooleanArray(upTo)
            if (upTo < 2)
                return isPrime

            Arrays.fill(isPrime, true)
            isPrime[0] = false
            isPrime[1] = false
            for (i in 2..upTo - 1) {
                if (isPrime[i])
                {
                    var j: Int = i * i
                    while (j < upTo)
                    {
                        isPrime[j] = false
                        j += i
                    }
                }
                if (i * i >= upTo)
                    break
            }
            return isPrime
        }
        public open fun generateDivisorTable(upTo: Int): IntArray {
            var divisor: IntArray = IntArray(upTo)
            for (i in 1..upTo - 1) divisor[i] = i
            for (i in 2..upTo - 1) {
                if (divisor[i] == i)
                {
                    var j: Int = i * i
                    while (j < upTo)
                    {
                        divisor[j] = i
                        j += i
                    }
                }

            }
            return divisor
        }
        public open fun powerInFactorial(_n: Long, p: Long): Long {
            var n = _n
            var result: Long = 0
            while (n != 0.toLong())
            {
                n /= p
                result += n
            }
            return result
        }
        public open fun sumDigits(number: CharSequence): Int {
            var result: Int = 0
            var i: Int = (number.length) - 1
            while (i >= 0)
            {
                result += digitValue((number[i]))
                i--
            }
            return result
        }
        public open fun digitValue(digit: Char): Int {
            if (Character.isDigit(digit))
                return digit - '0'

            if (Character.isUpperCase(digit))
                return digit + 10 - 'A'

            return digit + 10 - 'a'
        }
        public open fun longCompare(a: Long, b: Long): Int {
            if (a < b)
                return -1

            if (a > b)
                return 1

            return 0
        }
        public open fun generateBinomialCoefficients(n: Int): Array<LongArray> {
            var result: Array<LongArray> = Array<LongArray>(n + 1, { LongArray(n + 1) })
            for (i in 0..n) {
                result[i][0] = 1
                for (j in 1..i) result[i][j] = result[i - 1][j - 1] + result[i - 1][j]
            }
            return result
        }
        public open fun generateBinomialCoefficients(n: Int, module: Long): Array<LongArray> {
            var result: Array<LongArray> = Array<LongArray>(n + 1, { LongArray(n + 1) })
            if (module == 1.toLong())
                return result

            for (i in 0..n) {
                result[i][0] = 1
                for (j in 1..i) {
                    result[i][j] = result[i - 1][j - 1] + result[i - 1][j]
                    if (result[i][j] >= module)
                        result[i][j] -= module

                }
            }
            return result
        }
        public open fun generateBinomialRow(n: Int, module: Long): LongArray {
            var result: LongArray = generateReverse(n + 1, module)
            result[0] = 1
            for (i in 1..n) result[i] = result[i - 1] * (n - i + 1) % module * result[i] % module
            return result
        }
        public open fun representationInBase(_number: Long, base: Int): IntArray {
            var number = _number
            var basePower: Long = base.toLong()
            var exponent: Int = 1
            while (number >= basePower)
            {
                basePower *= base
                exponent++
            }
            var representation: IntArray = IntArray(exponent)
            for (i in 0..exponent - 1) {
                basePower /= base
                representation[i] = ((number / basePower).toInt())
                number %= basePower
            }
            return representation
        }
        public open fun trueDivide(a: Int, b: Int): Int {
            return (a - trueMod(a, b)) / b
        }
        public open fun trueMod(_a: Int, b: Int): Int {
            var a = _a
            a %= b
            a += b
            a %= b
            return a
        }
        public open fun trueMod(_a: Long, b: Long): Long {
            var a = _a
            a %= b
            a += b
            a %= b
            return a
        }
        public open fun factorial(n: Int): Long {
            var result: Long = 1
            for (i in 2..n) result *= i
            return result
        }
        public open fun factorial(n: Int, mod: Long): Long {
            var result: Long = 1
            for (i in 2..n) result = result * i % mod
            return result % mod
        }
        public open fun factorize(_number: Long): List<Pair<Long, Int>> {
            var number = _number
            var result: MutableList<Pair<Long, Int>> = ArrayList<Pair<Long, Int>>()
            for (i in 2..number) {
                if (number % i == 0.toLong())
                {
                    var power: Int = 0
                    do
                    {
                        power++
                        number /= i
                    }
                    while (number % i == 0.toLong())
                    result.add(Pair(i, power))
                }

            }
            if (number != 1.toLong())
                result.plus(Pair(number, 1))

            return result
        }
        public open fun getDivisors(number: Long): List<Long?>? {
            var primeDivisors: List<Pair<Long?, Int?>?>? = factorize(number)
            return getDivisorsImpl(primeDivisors, 0, (1).toLong(), ArrayList<Long?>())
        }
        private fun getDivisorsImpl(primeDivisors: List<Pair<Long?, Int?>?>?, index: Int, current_: Long,
                                         result: MutableList<Long?>?): List<Long?>? {
            var current = current_
            if (index == (primeDivisors?.size)!!)
            {
                result?.add(current)
                return result
            }

            var p: Long = primeDivisors?.get(index)?.first!!
            var power: Int = primeDivisors?.get(index)?.second!!
            for (i in 0..power) {
                getDivisorsImpl(primeDivisors, index + 1, current, result)
                current *= p
            }
            return result
        }
        public open fun power(base: Long, exponent: Long): Long {
            if (exponent == 0.toLong())
                return 1

            var result: Long = power(base, exponent shr 1)
            result = result * result
            if ((exponent and 1) != 0.toLong())
                result = result * base

            return result
        }
        public open fun power(base_: Long, exponent: Long, mod: Long): Long {
            var base = base_
            if (base >= mod)
                base %= mod

            if (exponent == 0.toLong())
                return 1 % mod

            var result: Long = power(base, exponent shr 1, mod)
            result = result * result % mod
            if ((exponent and 1) != 0.toLong())
                result = result * base % mod

            return result
        }
        public open fun lcm(a: Long, b: Long): Long {
            return a / gcd(a, b) * b
        }
        public open fun generateFibonacci(upTo: Long): LongArray? {
            var count: Int = 0
            var last: Long = 0
            var current: Long = 1
            while (current <= upTo)
            {
                var next: Long = last + current
                last = current
                current = next
                count++
            }
            return generateFibonacci(count, (-1).toLong())
        }
        public open fun generateFibonacci(count: Int, module: Long): LongArray {
            var result: LongArray = LongArray(count)
            if (module == -1.toLong())
            {
                if (count != 0)
                    result[0] = 1

                if (count > 1)
                    result[1] = 1

                for (i in 2..count - 1) result[i] = result[i - 1] + result[i - 2]
            }
            else
            {
                if (count != 0)
                    result[0] = 1 % module

                if (count > 1)
                    result[1] = 1 % module

                for (i in 2..count - 1) result[i] = (result[i - 1] + result[i - 2]) % module
            }
            return result
        }
        public open fun generateHappy(digits: Int): LongArray {
            var happy: LongArray = LongArray((1 shl (digits + 1)) - 2)
            happy[0] = 4
            happy[1] = 7
            var first: Int = 0
            var last: Int = 2
            for (i in 2..digits) {
                for (j in 0..last - first - 1) {
                    happy[last + 2 * j] = 10 * happy[first + j] + 4
                    happy[last + 2 * j + 1] = 10 * happy[first + j] + 7
                }
                var next: Int = last + 2 * (last - first)
                first = last
                last = next
            }
            return happy
        }
        public open fun generateFactorial(count: Int, module: Long): LongArray {
            var result: LongArray = LongArray(count)
            if (module == -1.toLong())
            {
                if (count != 0)
                    result[0] = 1

                for (i in 1..count - 1) result[i] = result[i - 1] * i
            }
            else
            {
                if (count != 0)
                    result[0] = 1 % module

                for (i in 1..count - 1) result[i] = (result[i - 1] * i) % module
            }
            return result
        }
        public open fun reverse(number: Long, module: Long): Long {
            return power(number, module - 2, module)
        }
        public open fun isPrime(number: Long): Boolean {
            if (number < 2)
                return false

            for (i in 2..number) {
                if (number % i.toLong() == 0.toLong())
                    return false

            }
            return true
        }
        public open fun generateReverse(upTo: Int, module: Long): LongArray {
            var result: LongArray = LongArray(upTo)
            if (upTo > 1)
                result[1] = 1

            for (i in 2..upTo - 1) result[i] = (module - module / i * result[(((module % i) as Int))] % module) % module
            return result
        }
        public open fun generateReverseFactorials(upTo: Int, module: Long): LongArray {
            var result: LongArray = generateReverse(upTo, module)
            if (upTo > 0)
                result[0] = 1

            for (i in 1..upTo - 1) result[i] = result[i] * result[i - 1] % module
            return result
        }
        public open fun generatePowers(base: Long, count: Int, mod: Long): LongArray {
            var result: LongArray = LongArray(count)
            if (count != 0)
                result[0] = 1 % mod

            for (i in 1..count - 1) result[i] = result[i - 1] * base % mod
            return result
        }
        public open fun nextPrime(from_: Long): Long {
            var from = from_
            if (from <= 2)
                return 2

            from += 1 - (from and 1)
            while (!isPrime(from))
                from += 2
            return from
        }
        public open fun binomialCoefficient(n: Int, m_: Int, mod: Long): Long {
            var m = m_
            if (m < 0 || m > n)
                return 0

            if (2 * m > n)
                m = n - m

            var result: Long = 1
            for (i in n - m + 1..n) result = result * i % mod
            return result * (BigInteger.valueOf(factorial(m, mod))?.modInverse(BigInteger.valueOf(mod)))!!.toLong() %
                    mod
        }
        public open fun isSquare(number: Long): Boolean {
            var sqrt: Long = Math.round(Math.sqrt((number).toDouble()))
            return sqrt * sqrt == number
        }
        public open fun findCommon(aRemainder_: Long, aMod_: Long, bRemainder_: Long, bMod_: Long): Long {
            var aRemainder = aRemainder_
            var aMod = aMod_
            var bRemainder = bRemainder_
            var bMod = bMod_
            var modGCD: Long = gcd(aMod, bMod)
            var gcdRemainder: Long = aRemainder % modGCD
            if (gcdRemainder != bRemainder % modGCD)
                return -1

            aMod /= modGCD
            aRemainder /= modGCD
            bMod /= modGCD
            bRemainder /= modGCD
            var aReverse: Long = BigInteger.valueOf(aMod)?.modInverse(BigInteger.valueOf(bMod))?.toLong()!!
            var bReverse: Long = BigInteger.valueOf(bMod)?.modInverse(BigInteger.valueOf(aMod))?.toLong()!!
            var mod: Long = aMod * bMod
            return (bReverse * aRemainder % mod * bMod + aReverse * bRemainder % mod * aMod) % mod * modGCD + gcdRemainder
        }
        public open fun generatePowers(base: Long, maxValue: Long): LongArray? {
            if (maxValue <= 0)
                return LongArray(0)

            var size: Int = 1
            var current: Long = 1
            while (maxValue / base >= current)
            {
                current *= base
                size++
            }
            return generatePowers(base, size, Long.MAX_VALUE)
        }
    }
}