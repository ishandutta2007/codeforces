import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        TaskC1 solver = new TaskC1();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC1 {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int m = in.readInt();
            int[] a = in.readIntArray(n);
            int[] w = in.readIntArray(n);
            long[][] p = new long[m + 1][m + 1];
            int sumUp = 0;
            int sumDown = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] == 1) {
                    sumUp += w[i];
                } else {
                    sumDown += w[i];
                }
            }
            long[][] pr = new long[m + 1][m + 1];
            long[][] next = new long[m + 1][m + 1];
            for (int i = 0; i < n; i++) {
                pr[0][0] = 1;
                for (int j = 0; j < m; j++) {
                    for (int k = 0; k <= j + 1; k++) {
                        Arrays.fill(next[k], 0, k + 1, 0);
                    }
                    for (int k = 0; k <= j; k++) {
                        long up = a[i] == 1 ? sumUp + k : sumDown - k;
                        long down = a[i] == 1 ? sumDown - (j - k) : sumUp + (j - k);
                        if (down < 0) {
                            continue;
                        }
                        long rev = IntegerUtils.reverse(up + down, MiscUtils.MODF);
                        for (int l = 0; l <= k; l++) {
                            long cur = w[i] + (a[i] == 1 ? l : -l);
                            if (cur < 0) {
                                continue;
                            }
                            next[k][l] += down * rev % MiscUtils.MODF * pr[k][l];
                            next[k][l] %= MiscUtils.MODF;
                            next[k + 1][l] += (up - cur) * rev % MiscUtils.MODF * pr[k][l];
                            next[k + 1][l] %= MiscUtils.MODF;
                            next[k + 1][l + 1] += cur * rev % MiscUtils.MODF * pr[k][l];
                            next[k + 1][l + 1] %= MiscUtils.MODF;
                        }
                    }
                    long[][] temp = pr;
                    pr = next;
                    next = temp;
                }
                long answer = 0;
                for (int j = 0; j <= m; j++) {
                    for (int k = 0; k <= j; k++) {
                        answer += pr[j][k] * (w[i] + (a[i] == 1 ? k : -k)) % MiscUtils.MODF;
                    }
                }
                answer %= MiscUtils.MODF;
                out.printLine(answer);
            }
        }

    }

    static class IntegerUtils {
        private static long _x;
        private static long _y;

        public static long trueMod(long a, long b) {
            a %= b;
            a += b;
            a %= b;
            return a;
        }

        public static long reverse(long number, long modulo) {
            extGcd(number, modulo);
            return trueMod(_x, modulo);
        }

        private static long extGcd(long a, long b) {
            if (a == 0) {
                _x = 0;
                _y = 1;
                return b;
            }
            long d = extGcd(b % a, a);
            long nx = _y - (b / a) * _x;
            _y = _x;
            _x = nx;
            return d;
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

        public int[] readIntArray(int size) {
            int[] array = new int[size];
            for (int i = 0; i < size; i++) {
                array[i] = readInt();
            }
            return array;
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

    static class MiscUtils {
        public static final int MODF = 998244353;

    }
}