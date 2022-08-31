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
        F solver = new F();
        solver.solve(1, in, out);
        out.close();
    }

    static class F {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int k = in.readInt();
            int[] a = in.readIntArray(n);
            int[] b = new int[n - k + 1];
            int[] queue = new int[n];
            int start = 0;
            int end = 0;
            for (int i = 0; i < k - 1; i++) {
                while (start < end && a[queue[end - 1]] <= a[i]) {
                    end--;
                }
                queue[end++] = i;
            }
            for (int i = k - 1; i < n; i++) {
                while (start < end && a[queue[end - 1]] <= a[i]) {
                    end--;
                }
                queue[end++] = i;
                if (queue[start] == i - k) {
                    start++;
                }
                b[i - k + 1] = a[queue[start]];
            }
            long answer = 0;
            int[] c = new int[n];
            for (int i = 1; i < k; i++) {
                int at = b.length - i;
                int length = 0;
                for (int pos = at; pos >= 0; pos -= k - 1) {
                    c[length++] = b[pos];
                }
                end = 0;
                long currentSum = 0;
                for (int j = 0; j < length; j++) {
                    while (0 < end && c[queue[end - 1]] <= c[j]) {
                        long last = end == 1 ? -1 : queue[end - 2];
                        currentSum -= c[queue[end - 1]] * (queue[end - 1] - last);
                        currentSum %= MiscUtils.MOD7;
                        end--;
                    }
                    long last = end == 0 ? -1 : queue[end - 1];
                    currentSum += c[j] * (j - last);
                    currentSum %= MiscUtils.MOD7;
                    answer += currentSum;
                    queue[end++] = j;
                }
            }
            answer %= MiscUtils.MOD7;
            if (answer < 0) {
                answer += MiscUtils.MOD7;
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

    static class MiscUtils {
        public static final int MOD7 = (int) (1e9 + 7);

    }
}