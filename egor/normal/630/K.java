import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
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
        TaskK solver = new TaskK();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskK {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            long n = in.readLong();
            long x = 1;
            for (int i = 2; i <= 10; i++) {
                x = IntegerUtils.lcm(i, x);
            }
            long phi = MultiplicativeFunction.PHI.calculate(x);
            long answer = (n / x) * phi;
            for (long i = (n / x) * x; i <= n; i++) {
                if (IntegerUtils.gcd(i, x) == 1) {
                    answer++;
                }
            }
            out.printLine(answer);
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

    static abstract class MultiplicativeFunction {
        public static final MultiplicativeFunction PHI = new MultiplicativeFunction() {

            protected long value(long p, int exponent, long power) {
                return power / p * (p - 1);
            }
        };

        protected abstract long value(long p, int exponent, long power);

        public long calculate(long argument) {
            long value = 1;
            for (long i = 2; i * i <= argument; i++) {
                if (argument % i == 0) {
                    int exponent = 0;
                    long power = 1;
                    do {
                        exponent++;
                        power *= i;
                        argument /= i;
                    } while (argument % i == 0);
                    value *= value(i, exponent, power);
                }
            }
            if (argument != 1) {
                value *= value(argument, 1, argument);
            }
            return value;
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

        public long readLong() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
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

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }

    static class IntegerUtils {
        public static long gcd(long a, long b) {
            a = Math.abs(a);
            b = Math.abs(b);
            while (b != 0) {
                long temp = a % b;
                a = b;
                b = temp;
            }
            return a;
        }

        public static long lcm(long a, long b) {
            return (a / gcd(a, b)) * b;
        }

    }
}