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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public static final int DAYS = 1000000;
        public static final long INFTY = 1000_000_000_000L;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int m = in.readInt();
            int k = in.readInt();
            int[] d = new int[m];
            int[] f = new int[m];
            int[] t = new int[m];
            int[] c = new int[m];
            IOUtils.readIntArrays(in, d, f, t, c);
            MiscUtils.decreaseByOne(d, f, t);
            int[] first = ArrayUtils.createArray(DAYS, -1);
            int[] next = new int[m];
            for (int i = 0; i < m; i++) {
                if (t[i] == -1) {
                    next[i] = first[d[i]];
                    first[d[i]] = i;
                }
            }
            long[] inbound = new long[DAYS];
            long[] current = ArrayUtils.createArray(n, INFTY);
            long result = INFTY * n;
            for (int i = 0; i < DAYS; i++) {
                for (int j = first[i]; j != -1; j = next[j]) {
                    if (c[j] < current[f[j]]) {
                        result -= current[f[j]];
                        current[f[j]] = c[j];
                        result += c[j];
                    }
                }
                inbound[i] = result;
            }
            Arrays.fill(first, -1);
            for (int i = 0; i < m; i++) {
                if (f[i] == -1) {
                    next[i] = first[d[i]];
                    first[d[i]] = i;
                }
            }
            Arrays.fill(current, INFTY);
            result = INFTY * n;
            long[] outbound = new long[DAYS];
            for (int i = DAYS - 1; i >= 0; i--) {
                for (int j = first[i]; j != -1; j = next[j]) {
                    if (c[j] < current[t[j]]) {
                        result -= current[t[j]];
                        current[t[j]] = c[j];
                        result += c[j];
                    }
                }
                outbound[i] = result;
            }
            long answer = Long.MAX_VALUE;
            for (int i = k + 1; i < DAYS; i++) {
                answer = Math.min(answer, inbound[i - k - 1] + outbound[i]);
            }
            if (answer >= INFTY) {
                answer = -1;
            }
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
        public static void decreaseByOne(int[]... arrays) {
            for (int[] array : arrays) {
                for (int i = 0; i < array.length; i++) {
                    array[i]--;
                }
            }
        }

    }

    static class IOUtils {
        public static void readIntArrays(InputReader in, int[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = in.readInt();
                }
            }
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

    static class ArrayUtils {
        public static int[] createArray(int count, int value) {
            int[] array = new int[count];
            Arrays.fill(array, value);
            return array;
        }

        public static long[] createArray(int count, long value) {
            long[] array = new long[count];
            Arrays.fill(array, value);
            return array;
        }

    }
}