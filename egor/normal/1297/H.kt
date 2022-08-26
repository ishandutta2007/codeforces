
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
        val solver = TaskH()
        val testCount = Integer.parseInt(`in`.next())
        for (i in 1..testCount) {
            solver.solve(i, `in`, out)
        }
        out.close()
    }

    internal class TaskH {
        fun solve(testNumber: Int, `in`: InputReader, out: OutputWriter) {
            val s = `in`.readString()
            val n = s.length
            val left = Array<Array<String?>>(n + 1) { arrayOfNulls(n + 1) }
            val right = Array<Array<String?>>(n + 1) { arrayOfNulls(n + 1) }
            val last = Array(n + 1) { BooleanArray(n + 1) }
            left[0][0] = ""
            right[0][0] = ""
            for (i in 1..n) {
                val let = s[i - 1]
                left[i][0] = ""
                right[i][0] = right[i - 1][0] + let
                left[0][i] = left[0][i - 1] + let
                right[0][i] = ""
                last[0][i] = true
                for (j in 1 until i) {
                    val ll = left[i - j][j - 1] + let
                    val rl = right[i - j][j - 1]
                    val lr = left[i - j - 1][j]
                    val rr = right[i - j - 1][j] + let
                    val mxl = MiscUtils.max(ll, rl!!)
                    val mxr = MiscUtils.max(lr!!, rr)
                    val mnl = MiscUtils.min(ll, rl)
                    val mnr = MiscUtils.min(lr, rr)
                    if (mxl.compareTo(mxr) < 0 || mxl.compareTo(mxr) == 0 && mnl.compareTo(mnr) < 0) {
                        left[i - j][j] = ll
                        right[i - j][j] = rl
                        last[i - j][j] = true
                    } else {
                        left[i - j][j] = lr
                        right[i - j][j] = rr
                    }
                }
            }
            var ans = ""
            var a = -1
            var b = -1
            for (i in 0..n) {
                val cur = MiscUtils.max(left[i][n - i]!!, right[i][n - i]!!)
                if (ans.isEmpty() || cur.compareTo(ans) < 0) {
                    ans = cur
                    a = i
                    b = n - i
                }
            }
            val answer = CharArray(n)
            while (a > 0 || b > 0) {
                if (last[a][b]) {
                    answer[a + b - 1] = 'R'
                    b--
                } else {
                    answer[a + b - 1] = 'B'
                    a--
                }
            }
            out.printLine(answer)
            /*        char[] answer = new char[n];
        int start = 0;
        while (true) {
            if (start + 1 == n) {
                answer[start] = 'R';
                out.printLine(answer);
                return;
            }
            int at = -1;
            char mn = (char) ('z' + 1);
            for (int i = start + 1; i < s.length(); i++) {
                if (s.charAt(i) < s.charAt(start)) {
                    fill(answer, start, i, 'R');
                    fill(answer, i, n, 'B');
                    out.printLine(answer);
                    return;
                }
                if (s.charAt(i) < mn) {
                    at = i;
                    mn = s.charAt(i);
                }
            }
            if (mn > s.charAt(start)) {
                fill(answer, start, n, 'R');
                out.printLine(answer);
                return;
            }
            fill(answer, start, at, 'R');
            StringBuilder left = new StringBuilder(s.substring(start, at));
            int pos = 0;
            for (int i = at; pos < left.length(); i++) {
                if (s.charAt(i) > left.charAt(pos)) {
                    answer[i] = 'R';
                    left.append(s.charAt(i));
                } else if (s.charAt(i) < left.charAt(pos)) {
                    fill(answer, i, n, 'B');
                    out.printLine(answer);
                    return;
                } else {
                    answer[i] = 'B';
                    pos++;
                }
            }
            start += 2 * left.length();
        }*/
        }

    }

    internal class InputReader(private val stream: InputStream) {
        private val buf = ByteArray(1024)
        private var curChar: Int = 0
        private var numChars: Int = 0
        private val filter: InputReader.SpaceCharFilter? = null

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

    internal object MiscUtils {
        fun <T : Comparable<T>> min(first: T, second: T): T {
            return if (first.compareTo(second) <= 0) {
                first
            } else second
        }

        fun <T : Comparable<T>> max(first: T, second: T): T {
            return if (first.compareTo(second) <= 0) {
                second
            } else first
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

        fun printLine(array: CharArray) {
            writer.println(array)
        }

        fun close() {
            writer.close()
        }

    }
}