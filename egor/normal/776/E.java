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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            long n = in.readLong();
            long k = in.readLong();
            boolean isF = true;
            while (n > 1 && k > 0) {
                if (isF) {
                    n = f(n);
                }
                isF = !isF;
                k--;
            }
            out.printLine(n % MiscUtils.MOD7);
        }

        private long f(long n) {
            if (n == 1) {
                return 1;
            }
            return MultiplicativeFunction.PHI.calculate(n);
        }

    }

    static class MiscUtils {
        public static final int MOD7 = (int) (1e9 + 7);

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
}