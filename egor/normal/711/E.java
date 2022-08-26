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
        static final long MOD = (long) (1e6 + 3);

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            long n = in.readLong();
            long k = in.readLong();
            long a2p = 0;
            long p2 = 1;
            for (long i = 1; i <= n; i++) {
                p2 *= 2;
                if (k < p2) {
                    a2p += n - i + 1;
                    break;
                }
                a2p += (k + p2 - 1) / p2;
            }
            if (k > p2) {
                out.printLine(1, 1);
                return;
            }
            long bexp = n % (MOD - 1) * (k % (MOD - 1)) - a2p;
            bexp %= MOD - 1;
            if (bexp < 0) {
                bexp += MOD - 1;
            }
            long b = IntegerUtils.power(2, bexp, MOD);
            long st = IntegerUtils.power(2, n, MOD);
            long a;
            if (st < k) {
                a = 0;
            } else {
                a = IntegerUtils.reverse(IntegerUtils.power(2, a2p, MOD), MOD);
                for (long i = st; i > st - k; i--) {
                    a *= i;
                    a %= MOD;
                }
            }
            a = b - a;
            if (a < 0) {
                a += MOD;
            }
            out.printLine(a, b);
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

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void printLine(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }

    static class IntegerUtils {
        public static long power(long base, long exponent, long mod) {
            if (base >= mod) {
                base %= mod;
            }
            if (exponent == 0) {
                return 1 % mod;
            }
            long result = power(base, exponent >> 1, mod);
            result = result * result % mod;
            if ((exponent & 1) != 0) {
                result = result * base % mod;
            }
            return result;
        }

        public static long reverse(long number, long module) {
            return power(number, module - 2, module);
        }

    }
}