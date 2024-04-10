import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Egor Kulikov (egor@egork.net)
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskB solver = new TaskB();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++) {
            solver.solve(i, in, out);
        }
        out.close();
    }

    static class TaskB {
        long[] numDivisors = MultiplicativeFunction.DIVISOR_COUNT.calculateUpTo(100001);

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int a = in.readInt();
            int b = in.readInt();
            int c = in.readInt();
            long answer = 0;
            int ab = IntegerUtils.gcd(a, b);
            int bc = IntegerUtils.gcd(b, c);
            int ac = IntegerUtils.gcd(a, c);
            int abc = IntegerUtils.gcd(ab, c);
            long exactA = numDivisors[a] - numDivisors[ab] - numDivisors[ac] + numDivisors[abc];
            answer += exactA *
                    (numDivisors[b] * numDivisors[c] - numDivisors[bc] * (numDivisors[bc] - 1) / 2);
            long exactB = numDivisors[b] - numDivisors[ab] - numDivisors[bc] + numDivisors[abc];
            answer += exactB *
                    (numDivisors[a] * numDivisors[c] - numDivisors[ac] * (numDivisors[ac] - 1) / 2);
            long exactC = numDivisors[c] - numDivisors[ac] - numDivisors[bc] + numDivisors[abc];
            answer += exactC *
                    (numDivisors[b] * numDivisors[a] - numDivisors[ab] * (numDivisors[ab] - 1) / 2);
            answer -= exactA * exactB * numDivisors[c];
            answer -= exactB * exactC * numDivisors[a];
            answer -= exactA * exactC * numDivisors[b];
            answer += exactA * exactB * exactC;
            long exactAB = numDivisors[ab] - numDivisors[abc];
            long exactBC = numDivisors[bc] - numDivisors[abc];
            long exactAC = numDivisors[ac] - numDivisors[abc];
            answer += exactAB * exactBC * exactAC;
            answer += exactAB * (exactAB + 1) / 2 * (exactAC + exactBC);
            answer += exactBC * (exactBC + 1) / 2 * (exactAB + exactAC);
            answer += exactAC * (exactAC + 1) / 2 * (exactAB + exactBC);
            answer += numDivisors[abc] * exactBC * (exactBC + 1) / 2;
            answer += numDivisors[abc] * exactAB * (exactAB + 1) / 2;
            answer += numDivisors[abc] * exactAC * (exactAC + 1) / 2;
            answer += numDivisors[abc] * (exactAB * exactAC + exactAB * exactBC + exactAC * exactBC);
            answer += numDivisors[abc] * (numDivisors[abc] + 1) / 2 * (exactAB + exactAC + exactBC);
            answer += numDivisors[abc] * (numDivisors[abc] + 1) * (numDivisors[abc] + 2) / 6;
            out.printLine(answer);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int readInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public String readString() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public String next() {
            return readString();
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }

    static abstract class MultiplicativeFunction {
        public static final MultiplicativeFunction DIVISOR_COUNT = new MultiplicativeFunction() {

            protected long value(long p, int exponent, long power) {
                return exponent + 1;
            }
        };

        protected abstract long value(long p, int exponent, long power);

        public long[] calculateUpTo(int upTo) {
            int[] divisor = IntegerUtils.generateDivisorTable(upTo);
            long[] result = new long[upTo];
            if (upTo <= 1) {
                return result;
            }
            result[1] = 1;
            for (int i = 2; i < upTo; i++) {
                int iDivided = i;
                int exponent = 0;
                do {
                    iDivided /= divisor[i];
                    exponent++;
                } while (iDivided % divisor[i] == 0);
                result[i] = result[iDivided] * value(divisor[i], exponent, i / iDivided);
            }
            return result;
        }

    }

    static class IntegerUtils {
        public static int gcd(int a, int b) {
            a = Math.abs(a);
            b = Math.abs(b);
            while (b != 0) {
                int temp = a % b;
                a = b;
                b = temp;
            }
            return a;
        }

        public static int[] generateDivisorTable(int upTo) {
            int[] divisor = new int[upTo];
            for (int i = 1; i < upTo; i++) {
                divisor[i] = i;
            }
            for (int i = 2; i * i < upTo; i++) {
                if (divisor[i] == i) {
                    for (int j = i * i; j < upTo; j += i) {
                        divisor[j] = i;
                    }
                }
            }
            return divisor;
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void printLine(long i) {
            writer.println(i);
        }

    }
}