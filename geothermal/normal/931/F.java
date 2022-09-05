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
 * @author Jay Leeds
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int[] prefix = new int[m];
            for (int i = 0; i < n; i++) {
                int a = in.nextInt() - 1;
                int b = in.nextInt();
                prefix[a]++;
                if (b < m) prefix[b]--;
            }

            int[] data = new int[m];
            int count = 0;
            for (int i = 0; i < m; i++) {
                count += prefix[i];
                data[i] = count;
            }

            int[] increasingIndices = new int[m + 2];
            for (int i = 0; i < m + 2; i++) {
                increasingIndices[i] = n + 1;
            }

            increasingIndices[0] = -1;
            int[] increaseData = new int[m];
            for (int i = 0; i < m; i++) {
                int lo = 0;
                int hi = m;
                while (lo <= hi) {
                    int mid = (lo + hi + 1) / 2;
                    if (increasingIndices[mid] <= data[i]) {
                        lo = mid + 1;
                    } else {
                        hi = mid - 1;
                    }
                }
                increaseData[i] = lo;
                increasingIndices[lo] = Math.min(increasingIndices[lo], data[i]);
            }

            int[] decreasingIndices = new int[m + 2];
            for (int i = 0; i < m + 2; i++) decreasingIndices[i] = n + 1;
            decreasingIndices[0] = -1;
            int[] decreaseData = new int[m];
            for (int i = m - 1; i >= 0; i--) {
                int lo = 0;
                int hi = m;
                while (lo <= hi) {
                    int mid = (lo + hi + 1) / 2;
                    if (decreasingIndices[mid] <= data[i]) {
                        lo = mid + 1;
                    } else hi = mid - 1;
                }

                decreaseData[i] = lo;
                decreasingIndices[lo] = Math.min(decreasingIndices[lo], data[i]);
            }

            int max = 0;
            for (int i = 0; i < m; i++) {
                max = Math.max(max, decreaseData[i] + increaseData[i] - 1);
            }
            out.printLine(max);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream; //Fast IO by Egor Kulikov, modified by myself
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

        public int nextInt() {
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

        public void printLine(int i) {
            writer.println(i);
        }

        public void close() {
            writer.close();
        }

    }
}